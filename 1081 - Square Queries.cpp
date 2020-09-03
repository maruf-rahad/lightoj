#include<bits/stdc++.h>
using namespace std;
int ara[510][510];
struct node
{

    int indx,indy;

};
node sparse[510][510][10];

void zero(int n,int x)
{
    int i,j,k;
    for(i=0;i<=n+5;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=x+1;k++)
            {
                sparse[i][j][k].indx = -1;
                sparse[i][j][k].indy = -1;
            }
        }
    }



}
void process(int n)
{
    int i,j,k,x1,x2,y1,y2,z;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            sparse[i][j][0].indx = i;
            sparse[i][j][0].indy = j;
        }
    }


    for(i=0; i<n; i++)
    {
        for(k=1; (1<<k)<=n; k++)
        {
            for(j=0; j+(1<<k)-1<n; j++)
            {
                x1 = sparse[i][j][k-1].indx;
                y1 = sparse[i][j][k-1].indy;
                z = j+(1<<(k-1));
                x2 = sparse[i][z][k-1].indx;
                y2 = sparse[i][z][k-1].indy;

                if(ara[x1][y1]>ara[x2][y2])
                {
                    sparse[i][j][k].indx = x1;
                    sparse[i][j][k].indy = y1;
                }
                else
                {
                    sparse[i][j][k].indx = x2;
                    sparse[i][j][k].indy = y2;
                }

            }
        }
    }
}

int query(int row,int col,int l)
{
    int x1,x2,y1,y2,high,k,mx,z,z2,low,i,j;
    low = row;
    k = log2(l);
    mx = -1;
    for(i=low; i<=low+l-1; i++)
    {
        x1 = sparse[i][col][k].indx;
        y1 = sparse[i][col][k].indy;
        z  = col+l-(1<<k);
        x2 = sparse[i][z][k].indx;
        y2 = sparse[i][z][k].indy;
        z2 = max(ara[x1][y1],ara[x2][y2]);
       // printf("%d %d\n",i,z2);
        mx = max(mx,z2);
    }
    return mx;
}
int main()
{
    //freopen("output.txt","w",stdout);
    int t,n,m,a,b,c,i,j,x,y,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int x = log2(n)+1;
       // zero(n,x);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&ara[i][j]);
            }
        }
        process(n);

      /*  for(i=0;i<n;i++)
        {
            printf("i=%d:\n",i);
            for(j=0;j<n;j++)
            {
                printf("j=%d:\n",j);
                for(k=0;k<x;k++)
                {
                    printf("%d %d %d\n",(1<<k),sparse[i][j][k].indx,sparse[i][j][k].indy);
                }
            }
        }*/


        printf("Case %d:\n",++k);
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            x = query(a-1,b-1,c);
            printf("%d\n",x);
        }

    }











    return 0;

}

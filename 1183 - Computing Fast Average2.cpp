#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int tree[mx*4];
int prop[mx*4];

void init(int node,int b,int e)
{
    tree[node] = 0;
    prop[node] = -1;
    if(b==e)
    {
        return;
    }
    int mid = (b+e)>>1;
    int left =  node<<1;
    int right = node<<1|1;

    init(left,b,mid);
    init(right,mid+1,e);
}
void propagate(int node,int b,int e)
{
    if(b==e||prop[node]==-1)
        return;

    int mid = (b+e)>>1;
    int left = node<<1;
    int right = node<<1|1;
    tree[left] = (mid-b+1)*prop[node];
    tree[right] = (e-mid)*prop[node];
    prop[left] = prop[node];
    prop[right] = prop[node];
    prop[node] = -1;

}
void update(int node,int b,int e,int i,int j,int val)
{
    if(b>j||e<i)
        return;

    propagate(node,b,e);
    if(b>=i&&e<=j)
    {
        tree[node] = (e-b+1)*val;
        prop[node] = val;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)>>1;

    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node] = tree[left]+tree[right];

}

int query(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)
        return 0;
    if(b>=i&&e<=j)
        return tree[node];

    propagate(node,b,e);

    int mid = (b+e)>>1;
    int left = node<<1;
    int right = node<<1|1;

    return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);


}


int main()
{
    int t,n,m,a,b,i,j,x,y,l,r,val,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        init(1,1,n);
        printf("Case %d:\n",++k);

        for(i=1; i<=m; i++)
        {
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d %d %d",&l,&r,&val);
                update(1,1,n,l+1,r+1,val);
            }
            else if(a==2)
            {
                scanf("%d %d",&l,&r);
                x = query(1,1,n,l+1,r+1);
                y = __gcd(x,r-l+1);
                if(x%(r-l+1)==0)
                {
                    printf("%d\n",x/(r-l+1));
                }
                else{
                    printf("%d/%d\n",x/y,(r-l+1)/y);
                }
            }

           // for(j=1; j<=30; j++)
          //  {
         //       printf("%d  %d  %d\n",j,tree[j],prop[j]);
         //   }
        }
    }



































    return  0;
}

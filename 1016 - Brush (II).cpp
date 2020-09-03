#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int y;
};
node ara[50020];
node ara2[50020];

bool cmp(node a,node b)
{
    if(a.y>b.y)return false;
    else if(a.y==b.y&&a.x>b.x)return false;

    return true;
}
int main()
{
    int t,n,m,a,b,i,j,x,y,sum,k = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&ara[i].x,&ara[i].y);
        }
        sort(ara+1,ara+n+1,cmp);
        //for(i=1;i<=n;i++)
       // {
       //     printf("%d %d\n",ara[i].x,ara[i].y);
     //   }
        a = 1;
        b = 1;
        sum = 0;
        while(1)
        {
            if((abs(ara[a].y-ara[b].y))>m)
            {
                sum++;
                a = b;
            }
            else
            {
                b++;
            }
            if(a>n||b>n)break;
        }
        printf("Case %d: %d\n",++k,sum+1);
    }














return 0;
}

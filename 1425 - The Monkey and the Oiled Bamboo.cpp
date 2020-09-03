#include<bits/stdc++.h>
using namespace std;
int ara[100010];
int ara2[100010];
int main()
{
    int t,n,m,a,b,i,j,mx,x,k=0;

    scanf("%d",&t);
    while(t--)
    {
        mx = -9;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        ara2[1] = ara[1];
        mx=  ara[1];
        for(i=2;i<=n;i++)
        {
            ara2[i] = ara[i]-ara[i-1];
            mx = max(mx,ara2[i]);
        }
        x = mx;
        for(i=1;i<=n;i++)
        {
            if(ara2[i]==x)
            {
                x--;
            }
            else if(ara2[i]>x)
            {
                mx++;
                x = mx;
            }
        }

        printf("Case %d: %d\n",++k,mx);

    }








return 0;
}

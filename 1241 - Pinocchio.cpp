#include<bits/stdc++.h>
using namespace std;
int ara[100];
int main()
{
 //   freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j=0,sum;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum  = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        ara[0] = 2;
        for(i=1;i<=n;i++)
        {
            if(ara[i]>ara[i-1])
            {
                a = ara[i]-ara[i-1];
                if(a>0)
                {
                    if(a%5==0)
                    {
                        sum+=a/5;
                    }
                    else{
                        sum+=(a/5+1);
                    }
                }
            }
        }
        printf("Case %d: %d\n",++j,sum);
    }











return 0;
}

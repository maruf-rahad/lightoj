#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull ara[2000];

ull gcd(ull a,ull b)
{
    if(a%b==0)return b;
    else gcd(b,a%b);
}

int main()
{
    freopen("output.txt","w",stdout);
    ull t,n,m,a,b,i,j,x,y,lcm,k = 0;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%llu",&ara[i]);
        }
        lcm = ara[1];
        for(i=2;i<=n;i++)
        {

            a = gcd(lcm,ara[i]);
            x = lcm;
            y = ara[i];
            if(lcm%a==0)
            {
                x = lcm/a;
                lcm = x*y;
            }
            else if(y%a==0){
                y = y/a;
                lcm = x*y;
            }
            else{
                lcm = (lcm*ara[i])/(gcd(lcm,ara[i]));
            }

        }
        printf("Case %llu: %llu\n",++k,lcm);
    }












return 0;
}

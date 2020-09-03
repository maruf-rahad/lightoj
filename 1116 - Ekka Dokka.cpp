#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,i,j=0,x,y,flag,n;

    scanf("%lld",&n);

    while(n--)
    {

        scanf("%lld",&a);
        printf("Case %lld: ",++j);

        flag = 0;
        if(a%2==1)
        {
            printf("Impossible\n");
            flag = 1;
        }

        x  = 2;
        y = a/2;

        while(y%2==0)
        {
            y = y/2;
            x = x*2;
        }

        if(flag==0)
        {
            if(y%2==1)
            {
                printf("%lld %lld\n",y,x);
            }
            else{
                printf("Impossible\n");
            }
        }












    }








return 0;
}

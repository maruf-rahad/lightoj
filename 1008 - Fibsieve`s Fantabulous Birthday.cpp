#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,i = 0,j,n,m,x,y,z,c;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld",&a);

        b = sqrt(a);

        if(b*b!=a)
        {
            b = b+1;
        }
        c = b*b;

        printf("Case %lld: ",++i);

        if(c%2==0)
        {
                if(c-a<b)
                {
                    x = c-a+1;

                printf("%lld %lld\n",b,x);

                }
                else{
                        x = c-b+1;
                        y = x - a;
                        z = b-y;


                printf("%lld %lld\n",z,b);
                }


        }
        else
        {
            if(c-a>b-1)
            {
                x = c - b+1;
                y = x-(a);
                z = b-y;


                printf("%lld %lld\n",b,z);


            }
            else{
                    x = c-a+1;
                printf("%lld %lld\n",x,b);

            }

        }



    }








return 0;
}

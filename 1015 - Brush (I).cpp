#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i = 0,j,m,sum;
    scanf("%d",&n);
    while(n--)
    {
        sum = 0;
        getchar();

        scanf("%d",&m);

        while(m--)
        {
            scanf("%d",&a);
            if(a>0)
            {
                sum+=a;
            }
        }

        printf("Case %d: %d\n",++i,sum);


    }





return 0;
}

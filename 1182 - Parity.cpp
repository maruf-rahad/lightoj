#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i=0,j,x,y,sum;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        sum = 0;
        printf("Case %d: ",++i);

        while(a!=0)
        {
            b = a%2;
            if(b==1)
            {
                sum++;
            }
            a = a/2;



        }
        if(sum%2==0)
        {
            printf("even\n");
        }
        else{
            printf("odd\n");
        }





    }






return 0;
}

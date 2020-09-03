#include<bits/stdc++.h>
using namespace std;
double ara[1000005];

void LogBairKortasi()
{
    for(int i=2;i<=1000004;i++)
    {
        ara[i]=ara[i-1]+log10(i);
    }
}

int main()
{
    LogBairKortasi();
    int n,a,i,j=0,b;
    double c;

    scanf("%d",&n);

    while(n--)
    {

        scanf("%d %d",&a,&b);
         printf("Case %d: ",++j);

        if(b==10)
        {
            printf("%d\n",(int)ara[a]+1);
        }
        else{


            c = (ara[a])*(log(10)/log(b));

            printf("%d\n",(int)c+1);

        }

    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define pie acos(-1)
int main()
{
    //freopen("output.txt","w",stdout);
    double a,b,x,y,z,c,d;
    int t,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        x = ((a-b)/c)*d;
        x+=b;
        x = ((pie*d)*(x*x+b*b+x*b))/3;

        printf("Case %d: ",++k);

        std::cout<<std::fixed;
        cout<<setprecision(9)<<x<<endl;

    }












return 0;
}

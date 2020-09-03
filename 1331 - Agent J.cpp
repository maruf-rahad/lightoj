#include<bits/stdc++.h>
using namespace std;
#define pie acos(-1)
int main()
{
    int t,k = 0;
    double a,b,c,x,y,z,n,m,sum,s,r1,r2,r3,k1,k2,k3,a1,a2,a3;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);

        x = r1+r2;
        y = r1+r3;
        z = r2+r3;

        s = (x+y+z)/2;
        s = sqrt(s*(s-x)*(s-y)*(s-z));

        k1 = acos((x*x+y*y-z*z)/(2*x*y));
        k1 = (k1*180)/pie;
        k2 = acos((x*x+z*z-y*y)/(2*x*z));
          k2 = (k2*180)/pie;
        k3 = acos((y*y+z*z-x*x)/(2*y*z));
          k3 = (k3*180)/pie;

        a1 = (k1*pie*r1*r1)/360;
        a2 = (k2*pie*r2*r2)/360;
        a3 = (k3*pie*r3*r3)/360;
        printf("Case %d: ",++k);
        std::cout<<std::fixed;
        cout<<setprecision(9)<<(s-(a1+a2+a3))<<endl;






    }














return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define pie acos(-1)

double dist(double a,double b,double x,double y)
{
    double z = sqrt((x-a)*(x-a)+(y-b)*(y-b));
    return z;
}
int main()
{
   //freopen("output.txt","w",stdout);
    int t,k=0;
    double ox,oy,ax,ay,bx,by,cx,z,a,b,c,x,y;

    scanf("%d",&t);
    while(t--)
    {
        cin>>ox>>oy>>ax>>ay>>bx>>by;

        x = dist(ox,oy,ax,ay);
        y = dist(ox,oy,bx,by);
        z = dist(ax,ay,bx,by);



        b = acos((x*x+y*y-z*z)/(2*x*y));
        //k1 = acos((x*x+y*y-z*z)/(2*x*y));

     //   b = (b*180)/pie;
     printf("Case %d: ",++k);
     std::cout<<std::fixed;

        cout<<setprecision(9)<<x*b<<endl;





    }












return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define pie acos(-1)
double binarysearch(double R,double x)
{
    double low = 0.000001,high,mid,y;
    high = R;
    for(int i = 0; i < 47; ++i)
    {
         mid =  (low+high)/2;
        y=((R*R)-(2.0*R*mid)-(mid*mid))/((R-mid)*(R-mid));
       // cout<<"mid = "<<mid<<" "<<cos(x)<<" "<<y<<endl;
        if(cos(x)<y)
        {
            low = mid;

        }
        else if(cos(x)>y){
            high = mid;
        }

        //if(abs(cos(x)-y)<eps)break;
    }
    return mid;
}


int main()
{
  //  freopen("output.txt","w",stdout);
    int t,k=0;
    double n,m,a,b,i,j,x,y,R,mid;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf",&R,&m);
        x = (((360/m)*pie)/180);
        x = binarysearch(R,x);

        std::cout<<std::fixed;

        cout<<"Case "<<++k<<": "<<setprecision(10)<<x<<endl;

    }








return 0;
}


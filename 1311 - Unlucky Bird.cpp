#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k=0;
    double a,b,c,n,m,i,j,x,y;


    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b>>c>>x>>y;

        n = (a*a)/(2.0*x);
        m = (b*b)/(2.0*y);
        i = a/x;
        j = b/y;

        printf("Case %d: ",++k);
        std:: cout<<std::fixed;
        cout<<setprecision(9)<<n+m<<" "<<setprecision(9)<<max(i,j)*c<<endl;
    }










return 0;
}

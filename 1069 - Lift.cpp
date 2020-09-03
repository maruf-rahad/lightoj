#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i = 0,j,x,y;

    scanf("%d",&n);

    while(n--)
    {
        scanf("%d %d",&a,&b);
        x = 19+abs(b-a)*4+a*4;

        printf("Case %d: %d\n",++i,x);



    }





return 0;

}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i,j,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);

        if(a>10)
        {
            b = a-10;
        }
        else{
            b = 0;
        }

        printf("%d %d\n",b,a-b);



    }







return 0;
}

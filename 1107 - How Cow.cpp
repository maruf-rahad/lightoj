#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i,j = 0,x1,x2,y1,y2,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("Case %d:\n",++j);

        scanf("%d",&n);

        while(n--)
        {
            scanf("%d %d",&a,&b);

            if(a>x1&&a<x2&&b>y1&&b<y2)
            {
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }




        }



    }




return 0;
}

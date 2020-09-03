#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("output.txt","w",stdout);
    int t,n,m,a,b,c,i,j,x,y,z,k=0,a1,a2,a3,b1,b2,b3,sum;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&b1,&b2,&b3);

        for(i=1;i<n;i++)
        {
            scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
            a1 = max(a1,a);
            a2 = max(a2,b);
            a3 = max(a3,c);
            b1 = min(b1,x);
            b2 = min(b2,y);
            b3 = min(b3,z);
        }
        sum  = (b1-a1)*(b2-a2)*(b3-a3);
        if(sum<0)sum = 0;
        printf("Case %d: %d\n",++k,sum);


    }








return 0;
}

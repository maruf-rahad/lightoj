#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,i,j,x,y,sum,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        int ara[a];
        for(j=0;j<a;j++)
        {
            scanf("%d",&ara[j]);

        }
        sort(ara,ara+a);
        sum=0;
        x=0;
        for(j=0;j<a&&j<b;j++){
            sum=sum+ara[j];
            if(sum<=c){
                x++;
            }
        }
        printf("Case %d: %d\n",i,x);
    }


return 0;
}

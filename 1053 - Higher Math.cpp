#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i,j=0,x,y;
    int ara[3];

    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<3;i++)
        {
            scanf("%d",&ara[i]);
        }
        sort(ara,ara+3);

        if(ara[0]*ara[0]+ara[1]*ara[1]==ara[2]*ara[2])
        {
            printf("Case %d: yes\n",++j);
        }
        else{
            printf("Case %d: no\n",++j);
        }


    }




return 0;
}

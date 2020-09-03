#include<bits/stdc++.h>
using namespace std;
int ara[200];
int main()
{
    int t,n,m,a,b,i,j,x,y,flag,sum,k=0;

    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        x = n;

        for(i=1;i<=n;i++)
        {
            a = *max_element(ara+1,ara+x+1);

            if(ara[x]==a)
            {
                x--;
            }
            else{
                for(j=1;j<=x;j++)
                {
                    if(ara[j]==a)
                    {
                        swap(ara[a],ara[j]);
                        sum++;
                        x--;
                    }
                }
            }
        }
        printf("Case %d: %d\n",++k,sum);


    }










return 0;
}

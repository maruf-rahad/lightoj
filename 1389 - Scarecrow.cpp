#include<bits/stdc++.h>
using namespace std;
char ch[200];
int main()
{
    int t,n,m,a,b,i,j,sum,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(i=1;i<=n;i++)
        {
            scanf("%c",&ch[i]);
        }

        sum = 0;
        for(i=1;i<=n;i++)
        {
            if(ch[i]=='.')
            {
                sum++;
                i+=2;
            }
        }
        printf("Case %d: %d\n",++k,sum);
    }











return 0;
}

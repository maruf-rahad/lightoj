#include<bits/stdc++.h>
using namespace std;
int ara[1010];
vector<int>v;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,a,b,i,j,x,y,sum,flag,t,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        sum = 0;
        v.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
            sum+=ara[i];
        }
        sum/=m;

        x = 0;
        for(i=1;i<=n;i++)
        {
            x+=ara[i];
            if(n-i+1==m)
            {
                m--;
                v.push_back(x);
                x = 0;
                continue;
            }
            if(x<sum&&n-i+1>m)
            {
                continue;
            }
            else{
                v.push_back(x);
                x = 0;

            }

        }

        printf("Case %d: %d\n",++k,*max_element(v.begin(),v.end()));

    }











return 0;
}

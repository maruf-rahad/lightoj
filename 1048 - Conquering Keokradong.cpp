#include<bits/stdc++.h>
using namespace std;
int ara[1010];
vector<int>v;
bool check(int mid,int n,int m)
{
    int sum = 0;
    int cnt = 0;
    int flag = 0;
    int x = m;
    v.clear();
    for(int i=1; i<=n; i++)
    {
        if(sum+ara[i]<=mid&&n-i>=x-1)
        {
            sum+=ara[i];
        }
        else
        {
            cnt++;
            x--;
            sum = ara[i];
        }
    }
    cnt++;

   // printf("cnt %d %d %d\n",cnt,m,mid);
    if(cnt>m)
    {
        return false;
    }

    return true;

}
int binary_searchh(int low,int high,int n,int m)
{
    int mid,ans=0;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(check(mid,n,m))
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }

    int sum = 0;
    int cnt = 0;
    int flag = 0;
    v.clear();
    int x = m;
    for(int i=1; i<=n; i++)
    {
        if(sum+ara[i]<=ans&&n-i>=x-1)
        {
            flag = 1;
            sum+=ara[i];
        }
        else
        {
            if(flag==1)
            {
                v.push_back(sum);
                flag = 0;
            }
            sum = ara[i];
            flag = 1;
            x--;
        }
    }
    v.push_back(sum);
    return ans;

}

int main()
{

    int t,n,m,a,b,i,j,x,y,sum,mx,k=0;

    scanf("%d",&t);
    while(t--)
    {
        mx = -9;
        sum=0;
        scanf("%d %d",&n,&m);
        m++;
        n++;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
            mx = max(mx,ara[i]);
            sum+=ara[i];
        }
        x = binary_searchh(mx,sum,n,m);

        printf("Case %d: %d\n",++k,x);
        for(i=0;i<v.size();i++){
            printf("%d\n",v[i]);
        }

    }







    return 0;
}

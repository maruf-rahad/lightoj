#include<bits/stdc++.h>
using namespace std;
#define mx 10000000
#define ll long long
bool ara[mx+10];
vector<int>v;
int sz;

void sieve()
{
    ll i,j;

    for(i=4;i<=mx;i+=2)ara[i] = true;

    v.push_back(2);
    for(i=3;i<=mx;i+=2)
    {
        if(ara[i]==0)
        {
            v.push_back(i);
            for(j=i*i;j<=mx;j+=(2*i))ara[j] = true;
        }
    }
}

int solve(int n)
{
    int sum = 0,i;

    for(i=0;i<sz&&v[i]<=n/2;i++)
    {
        if(ara[n-v[i]]==false)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    sieve();
    sz = v.size();
    int t,n,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++k,solve(n));
    }














return 0;
}

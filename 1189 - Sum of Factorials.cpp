#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>v;
ll ara[100];

void fact()
{
    ll i;
    ara[0] = 1;
    for(i=1; i<=20; i++)
    {
        ara[i] = i*ara[i-1];
    }
}

int main()
{
    fact();
    ll n,m,b,i,j,sum,t,k=0,a;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum = n;
        v.clear();

        for(i=20;i>=0;i--)
        {
            if(ara[i]<=sum)
            {

                sum-=ara[i];
                v.push_back(i);
            }
        }
        a = v.size()-1;
        if(sum==0){
        printf("Case %lld: %lld!",++k,v[a]);
        for(i=v.size()-2;i>=0;i--)
        {
            printf("+%lld!",v[i]);
        }
        printf("\n");
        }
        else{
            printf("Case %lld: impossible\n",++k);
        }


    }











    return 0;
}

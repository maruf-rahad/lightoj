#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

ll cost[222];
ll dis[222];
vector<pair<ll,ll> >G[222];

void zero(ll n)
{
    for(ll i = 0; i<=n+5; i++)
    {
        G[i].clear();
        cost[i] = 0;
        dis[i] = 1e18;
    }
}

void belmanford(ll u,ll n)
{
    ll i,j,k;
    dis[u] = 0;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            for(k=0; k<G[j].size(); k++)
            {
                if(dis[j]!=1e18&&(dis[j]+G[j][k].S<dis[G[j][k].F]))
                {
                    dis[G[j][k].F] = dis[j]+G[j][k].S;
                }
            }
        }
    }

    int flag = 0;
    for(j=1; j<=n; j++)
    {
        for(k=0; k<G[j].size(); k++)
        {
            if(dis[j]!=1e18&&(dis[j]+G[j][k].S<dis[G[j][k].F]))
            {
                dis[G[j][k].F] = 1e18;
            }
        }
    }
}
int main()
{
    ll t,n,m,a,b,i,j,x,y,casee = 0;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        zero(n);

        for(i=1; i<=n; i++)
        {
            scanf("%lld",&cost[i]);
        }

        scanf("%lld",&m);
        for(i=1; i<=m; i++)
        {
            scanf("%lld %lld",&a,&b);

            x = powl(cost[b]-cost[a],3);

            G[a].push_back({b,x});
        }

        printf("Case %lld:\n",++casee);

        belmanford(1,n);

        scanf("%lld",&m);

        while(m--)
        {
            scanf("%lld",&a);

            if(dis[a]==1e18||dis[a]<3)
            {
                printf("?\n");
            }
            else
            {
                printf("%lld\n",dis[a]);
            }

        }
    }

    return 0;
}

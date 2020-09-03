#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair

vector<pair<int,int> >G[30100];
int visited[30100];
int dis[30100];
void zero(int n)
{
    for(int i=0;i<=n+5;i++)
    {
        G[i].clear();
        visited[i] = 0;
        dis[i] = 0;
    }
}
void zero2(int n)
{
    for(int i=0;i<=n+5;i++)
    {
        dis[i] = 0;
        visited[i] = 0;
    }
}
void dfs(int u)
{
    visited[u] = 1;

    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i].F;
        int c = G[u][i].S;
        if(visited[v]==0)
        {
            dis[v] = dis[u]+c;
            dfs(v);
        }
    }
}
int main()
{
    int t,n,m,a,b,i,j,x,y,c,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        zero(n);

        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(MP(b,c));
            G[b].push_back(MP(a,c));
        }

        dfs(0);
        int mx = -9;
        for(i=0;i<n;i++)
        {
            if(dis[i]>mx)
            {
                mx = dis[i];
                x = i;
            }
        }
        zero2(n);

        dfs(x);
        mx = -9;
        for(i=0;i<n;i++)
        {
            if(dis[i]>mx)
            {
                mx = dis[i];
                y = i;
            }
        }
        printf("Case %d: %d\n",++k,mx);

    }












return 0;
}

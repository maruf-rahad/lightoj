#include<bits/stdc++.h>
using namespace std;
vector<int>G[11111];
int visited[11111];
int d[11111];
int low[11111];
int parent[11111];
int tim,sum;
int arti[11111];

void zero(int n)
{
    tim = 0;
    sum = 0;
    for(int i=0;i<=n+5;i++)
    {
        G[i].clear();
        visited[i] = 0;
        low[i] = 0;
        d[i] = 0;
        parent[i] = i;
        arti[i] = 0;
    }
}

void articulation(int u)
{
    visited[u] = 1;
    tim++;
    d[u] = tim;
    low[u] = tim;
    int child = 0;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];

        if(v==parent[u])continue;
        if(visited[v]==1)
        {
            low[u] = min(low[u],d[v]);
        }
        if(visited[v]==0)
        {
            parent[v] = u;
            child++;
            articulation(v);
            low[u] = min(low[u],low[v]);
            if(d[u]<=low[v]&&u!=1)
            {
                arti[u] = 1;
            }
        }

    }

    if(child>1&&u==1)
    {
        arti[1] = 1;
    }
}
int main()
{
   // freopen("output.txt","w",stdout);
    int n,m,a,b,i,j,t,k = 0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        zero(n);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        articulation(1);

        for(i=1;i<=n;i++)
        {
            if(arti[i]>0)
                sum++;
        }
          printf("Case %d: %d\n",++k,sum);








    }














return 0;
}

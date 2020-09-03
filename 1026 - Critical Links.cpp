#include<bits/stdc++.h>
using namespace std;
#define mx 111

vector<int>G[mx];
vector<int>arti[mx];
int visited[mx];
int parent[mx];
int d[mx];
int low[mx];
int tim,sum;

void zero(int n)
{
    for(int i = 0;i<=n+5;i++)
    {
        G[i].clear();
        visited[i] = 0;
        low[i] = 0;
        d[i] = 0;
        parent[i] = i;
        arti[i].clear();
    }
}

void articulation(int u)
{
    visited[u] = 1;
    tim++;
    d[u] = tim;
    low[u] = tim;

    for(int i = 0;i<G[u].size();i++)
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
            articulation(v);
            low[u] = min(low[u],low[v]);
            if(d[u]<low[v])
            {
                sum++;
                arti[min(u,v)].push_back(max(u,v));
               //  printf("%d %d %d\n",u,v,arti[min(u,v)].size());

            }
        }
    }
}
int main()
{
    //freopen("output.txt","w",stdout);

    int n,m,a,b,i,j,t,k = 0;
    char str;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        zero(n);

        for(i=1;i<=n;i++)
        {
            scanf("%d%c%c%d%c",&a,&str,&str,&m,&str);
            for(j=1;j<=m;j++)
            {
                scanf("%d",&b);
                G[a].push_back(b);
                G[b].push_back(a);

            }
        }
        sum = 0;
        for(i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                articulation(i);
            }
        }

        printf("Case %d:\n%d critical links\n",++k,sum);

        for(i=0;i<=n;i++)
        {
            if(arti[i].size()>0)
            {
                sort(arti[i].begin(),arti[i].end());

                for(j=0;j<arti[i].size();j++)
                {
                    printf("%d - %d\n",i,arti[i][j]);
                }
            }
        }

    }





























return 0;
}

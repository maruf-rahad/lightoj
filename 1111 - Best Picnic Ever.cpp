#include<bits/stdc++.h>
using namespace std;
vector<int>G[1010];
vector<int>vec;
int visited[1010];
int cnt[1010];
void zero(int n)
{
    vec.clear();
    for(int i=0;i<=n+5;i++)
    {
        G[i].clear();
        cnt[i] =  0;
        visited[i] = 0;
    }
}
void zero2(int n)
{
    for(int i=0;i<=n+5;i++)
    {
        visited[i] = 0;
    }
}

void dfs(int u)
{
    visited[u] = 1;
    cnt[u]++;
    for(int i=0;i<G[u].size();i++)
    {
        int v = G[u][i];
        if(visited[v]==0)
        {
            dfs(v);
        }
    }
}
int main()
{
    int t,n,m,k,a,b,i,j,x=0,y;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&k,&n,&m);
        zero(n);
        for(i=1;i<=k;i++)
        {
            scanf("%d",&a);
            vec.push_back(a);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
        }

        for(i=0;i<vec.size();i++)
        {
            zero2(n);
            dfs(vec[i]);
        }
        int sum = 0;
        for(i=0;i<=n;i++)
        {
            if(cnt[i]==k)sum++;
        }

        printf("Case %d: %d\n",++x,sum);
    }





































return 0;
}

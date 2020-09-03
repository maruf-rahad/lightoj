#include<bits/stdc++.h>
using namespace std;
#define mx 50010
vector<pair<int,pair<int,int> > >v;
vector<pair<int,int> >G[mx];
int visited[mx];
int level[mx];
int parent[mx];
int par[mx];
struct node{
    int par;
    int maxi;
};
node sparse[mx][20];


void make(int n,int m)
{
    v.clear();
    for(int i=1;i<=n+5;i++)
    {
        G[i].clear();
        par[i] = i;
        parent[i] = 0;
        visited[i] = 0;
        level[i] = 0;
        for(int j=0;j<=m+2;j++)
        {
            sparse[i][j].par = -1;
            sparse[i][j].maxi = -1;
        }
    }
}
int findParent(int a)
{
    if(a==par[a])return a;
   par[a] = findParent(par[a]);
    return par[a];
}
void spanningTree(int n)
{
    int i,j,s,a,b,c,x,y;
    s = v.size();
    for(i=0;i<s;i++)
    {
        a = v[i].second.first;
        b = v[i].second.second;
        c = v[i].first;
        x = findParent(a);
        y = findParent(b);
        if(x!=y)
        {
            par[y] = x;
            G[x].push_back({y,c});
            G[y].push_back({x,c});
        }
    }
}
void bfs(int u)
{
    visited[u] = 1;
    parent[u] = -1;
    queue<int>q;
    q.push(u);

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i].first;
            int c = G[u][i].second;
            if(visited[v]==0)
            {
                visited[v] = 1;
                level[v] = level[u]+1;
                parent[v] = u;
                sparse[v][0].par = u;
                sparse[v][0].maxi = c;
                q.push(v);
            }
        }
    }
}
void lca_init(int n)
{
    int i,j;
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(sparse[i][j-1].par!=-1&&sparse[sparse[i][j-1].par][j-1].par!=-1)
            {
                sparse[i][j].par = sparse[sparse[i][j-1].par][j-1].par;
                sparse[i][j].maxi = max(sparse[i][j-1].maxi,sparse[sparse[i][j-1].par][j-1].maxi);
            }
        }
    }
}
int lca_query(int n,int p,int q)
{
    if(level[p]<level[q])
    {
        int temp = p;
        p = q;
        q = temp;
    }
    int log = 1;
    while(1)
    {
        if((1<<log)>level[p])break;
        log++;
    }
    int mxx = -1;
    for(int i=log;i>=0;i--)
    {
        if(level[p]-(1<<i)>=level[q])
        {
            mxx = max(mxx,sparse[p][i].maxi);
            p = sparse[p][i].par;
        }
    }
    if(p==q)return mxx;

    for(int i=log;i>=0;i--)
    {
        if(sparse[p][i].par!=-1&&sparse[p][i].par!=sparse[q][i].par)
        {
            mxx = max(mxx,max(sparse[p][i].maxi,sparse[q][i].maxi));
            p = sparse[p][i].par;
            q = sparse[q][i].par;
        }
    }
    return max(mxx,max(sparse[p][0].maxi,sparse[q][0].maxi));
}
int main()
{
    int t,n,m,a,b,c,i,j,x,y,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        x = log2(n)+1;
        make(n,x);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            v.push_back({c,{a,b}});
        }
        sort(v.begin(),v.end());
        spanningTree(n);
        bfs(1);
        lca_init(n);

        scanf("%d",&m);
        printf("Case %d:\n",++k);
        while(m--)
        {
            scanf("%d %d",&a,&b);
            x = lca_query(n,a,b);
            printf("%d\n",x);
        }
    }

return 0;
}

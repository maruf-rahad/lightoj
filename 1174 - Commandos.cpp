#include<bits/stdc++.h>
using namespace std;
vector<int>G[120];
int visited[120];
int dis1[120];
int dis2[120];
int flag;
void zero(int n)
{
    for(int i=0; i<=n+10; i++)
    {
        G[i].clear();
        visited[i] = 0;
        dis1[i] = 0;
        dis2[i] = 0;
    }
}
void zero2(int n)
{
    for(int i=0; i<=n+10; i++)
    {
        visited[i] = 0;
    }
}

void bfs(int u)
{
    visited[u] = 1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(visited[v]==0)
            {
                visited[v] = 1;
                dis1[v] = dis1[u]+1;
                q.push(v);
            }
        }
    }

}

void bfs2(int u,int ds,int choltase)
{
    visited[u] = 1;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(v==ds)
            {
                dis2[choltase] = visited[u];
                return;
            }
            else if(visited[v]==0)
            {
                visited[v] = visited[u]+1;
                q.push(v);
            }
        }
    }

}
int main()
{
  //  freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j,x,y,st,ds,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        zero(n);

        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        scanf("%d %d",&st,&ds);
        bfs(st);



        for(i=0;i<n;i++)
        {
            if(i!=ds){
            zero2(n);
            flag = 0;
            bfs2(i,ds,i);
            }
        }
        int mx = -9;
        for(i=0;i<n;i++)
        {
            dis2[i] = dis1[i]+dis2[i];
            if(dis2[i]>mx)
            {
                mx = dis2[i];
            }
        }
        printf("Case %d: %d\n",++k,mx);

    }






























    return 0;

}

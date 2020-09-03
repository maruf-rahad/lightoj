#include<bits/stdc++.h>
using namespace std;
vector<int>G[100010];
int visited[100010];
int mark[20010];
int x,y;
void zero(int n)
{
    for(int i=0;i<=n+5;i++)
    {
        visited[i] = 0;
        G[i].clear();
        mark[i] = 0;
    }
}

void bfs(int u)
{
    x++;
    visited[u] = 1;
    queue<int>q;
    q.push(u);

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];

            if(visited[u]==1&&visited[v]==0)
            {
                visited[v] = 2;
                q.push(v);
                y++;
            }
            else if(visited[u]==2&&visited[v]==0)
            {
                visited[v] = 1;
                q.push(v);
                x++;
            }
        }
    }
}
int main()
{

    int t,n,m,a,b,i,j,sum,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        zero(20010);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
            mark[a] = 1;
            mark[b] = 1;
        }
        sum = 0;
        for(i=1;i<=20000;i++)
        {
            if(mark[i]==1&&visited[i]==0)
            {
                x = 0;
                y = 0;
                bfs(i);
                sum+=max(x,y);
            }
        }


        printf("Case %d: %d\n",++k,sum);
    }


































    return 0;
}

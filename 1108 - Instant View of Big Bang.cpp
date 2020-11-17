#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

vector<pair<int,int> > G[1111];
vector<int>RG[1111];
vector<int>ans;
vector<int>vv;
int visited[1111];
int dis[1111];

void zero(int n)
{
    ans.clear();
    vv.clear();
    for(int i=0;i<=n+10;i++)
    {
        G[i].clear();
        RG[i].clear();
        visited[i] = 0;
        dis[i] = 1e7;
    }
}

int Bellman_Ford(int n)
{
    int i,j,k,u,uc,v,uvc;

    for(i = 0 ;i< n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<G[j].size();k++)
            {
                u = j;
                uc = dis[u];
                v = G[u][k].F;

                uvc = G[u][k].S;

                if(uc+uvc<dis[v])
                {
                    dis[v] = uc+uvc;
                }

            }
        }

    }
    int flag = 0;
    for(j=0;j<n;j++)
        {
            for(k=0;k<G[j].size();k++)
            {
                u = j;
                uc = dis[u];
                v = G[u][k].F;
                uvc = G[u][k].S;

                if(uc+uvc<dis[v])
                {
                    dis[v] = uc+uvc;
                    vv.push_back(v);
                    flag = 1;
                }
            }
        }
        return flag;
}

void dfs(int u)
{
    visited[u] = 1;
    ans.push_back(u);

    int sz = RG[u].size();
    for(int i = 0;i<sz ;i++)
    {
        int v = RG[u][i];

        if(visited[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
   // freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j,x,y,casee = 0,c;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        zero(n);

        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            G[b].push_back({a,c});
            RG[b].push_back(a);
        }


       x = Bellman_Ford(n);

        printf("Case %d:",++casee);

        if(x==0)printf(" impossible\n");
        else
        {

            int sz = vv.size();
            for(i=0;i<sz;i++)
            {
                if(visited[vv[i]]==0)
                {
                    dfs(vv[i]);
                }
            }
            sort(ans.begin(),ans.end());
            sz = ans.size();

            for(i=0;i<sz;i++)
            {
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }

return 0;
}

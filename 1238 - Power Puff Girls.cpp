#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair

char ch[30][30];
int visited[30][30];
int cnt[30][30];
vector<int>v;
int row[4] = {0,0,1,-1};
int col[4] = {1,-1,0,0};
void zero(int n,int m)
{
    int i,j;
    for(i=0;i<=n+5;i++)
    {
        for(j=1;j<=m+5;j++)
        {
            visited[i][j] = 0;
            cnt[i][j] = 0;
        }
    }
}

int bfs(int x,int y,int d1,int d2,int n,int m)
{
    int xx,yy,i,j;

    visited[x][y] = 0;

    queue<pair<int,int> >q;
    q.push(MP(x,y));

    while(!q.empty())
    {
        x = q.front().F;
        y = q.front().S;
        q.pop();
        for(i=0;i<4;i++)
        {
            int xx = x+row[i];
            int yy = y+col[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&visited[xx][yy]==0&&ch[xx][yy]!='#'&&ch[xx][yy]!='m')
            {
                q.push(MP(xx,yy));
                visited[xx][yy] = 1;
                cnt[xx][yy] = cnt[x][y]+1;
                if(xx==d1&&yy==d2)
                {
                    return cnt[xx][yy];
                }
            }
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);

    int t,n,m,i,j,a1,a2,a3,b1,b2,b3,c1,d1,d2,x,y,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);

        getchar();
        zero(n,m);
        v.clear();
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%c",&ch[i][j]);
                if(ch[i][j]=='a')
                {
                    a1 = i;
                    b1 = j;
                }
                else if(ch[i][j]=='b')
                {
                    a2 = i;
                    b2 = j;
                }
                else if(ch[i][j]=='c')
                {
                    a3 = i;
                    b3 = j;
                }
                else if(ch[i][j]=='h')
                {
                    d1 = i;
                    d2 = j;
                }
            }
            getchar();
        }
       // printf("%d %d %d %d %d %d %d %d %d %d\n",a1,b1,a2,b2,a3,b3,d1,d2,n,m);
       // x = bfs(a1,b1,d1,d2,n,m);
       // printf("%d\n",x);
        v.push_back(bfs(a1,b1,d1,d2,n,m));
        zero(n,m);
         v.push_back(bfs(a2,b2,d1,d2,n,m));
         zero(n,m);
          v.push_back(bfs(a3,b3,d1,d2,n,m));

    printf("Case %d: %d\n",++k,*max_element(v.begin(),v.end()));

    }
























return 0;
}

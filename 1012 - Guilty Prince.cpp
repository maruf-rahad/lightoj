#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[30][30];
int visited[30][30];
void zero()
{
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            visited[i][j] = 0;
        }
    }

}
void dfs(int x,int y)
{
    int xx,yy;

    if(x>n||x<1||y>m||y<1||ch[x][y]=='#')
        return;

    visited[x][y] = 1;

    xx = x;
    yy = y+1;
    if(visited[xx][yy]==0)
    {
        dfs(xx,yy);
    }
    xx = x;
    yy = y-1;
    if(visited[xx][yy]==0)
    {
        dfs(xx,yy);
    }
    xx = x+1;
    yy = y;
    if(visited[xx][yy]==0)
    {
        dfs(xx,yy);
    }
    xx = x-1;
    yy = y;
    if(visited[xx][yy]==0)
    {
        dfs(xx,yy);
    }

    if(visited[xx][yy]==0)
    {
        dfs(xx,yy);
    }


}

int main()
{
    int i,j,x,y,t,a,b,k=0;
    char str;

    scanf("%d",&t);
    scanf("%c",&str);


    while(t--)
    {
        scanf("%d %d",&m,&n);
        scanf("%c",&str);
        zero();

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%c",&ch[i][j]);
                if(ch[i][j]=='@')
                {
                    a = i;
                    b = j;
                }
            }
            scanf("%c",&str);
        }

        dfs(a,b);
        int sum = 0;

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(visited[i][j]==1)sum++;

            }

        }
        printf("Case %d: %d\n",++k,sum);




        }









        return 0;
    }

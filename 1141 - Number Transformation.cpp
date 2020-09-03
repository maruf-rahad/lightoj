#include<bits/stdc++.h>
using namespace  std;
int ara[1010];
vector<int>prime[1010];
vector<int>v;
vector<int>v2;
int visited[1100];
int cnt[1100];
int n,m,flag;
map<int,int>mp;
map<int,int> :: iterator  it;

void sieve()
{
    int i,j;
    ara[0] = 1;
    ara[1] = 1;
    v.push_back(2);

    for(i=4;i<=1010;i+=2)
    {
        ara[i] = 1;
    }
    for(i=3;i<=1000;i+=2)
    {
        if(ara[i]==0)
        {
            v.push_back(i);
            for(j=i*i;j<=1010;j+=i)
            {
                ara[j] = 1;
            }
        }
    }
}
void zero()
{
    mp.clear();
    for(int i = 0;i<=m+2;i++)
    {
        visited[i] = 0;
        cnt[i] = 0;
    }
}

void factor()
{
    int i,j;
    for(i=1;i<=1005;i++)
    {
        if(ara[i]==0)
        {
            for(j=i*2;j<=1005;j+=i)
            {
                prime[j].push_back(i);
            }
        }
    }
}

int bfs(int a)
{
    int i;
    queue<int>q;
    q.push(a);
    visited[a] = 1;
    while(!q.empty())
    {
        int a = q.front();
        //printf("now %d\n",a);
        if(a==m)
        {
         //  printf("yes\n");
            flag = 1;
            return cnt[a];
        }
        q.pop();
        for(i=0;i<prime[a].size();i++)
        {
            int b = a+prime[a][i];
            //printf("b = %d\n",b);
            if(b<=m&&visited[b]==0)
            {
                visited[b] = 1;
                cnt[b] = cnt[a]+1;
               // printf("pushing %d\n",b);
                q.push(b);

            }
        }
    }
}

int main()
{
    //freopen("output.txt","w",stdout);
    sieve();
    factor();
    /*for(int i=1;i<=1000;i++)
    {
        printf("%d : ",i);
        for(int j=0;j<prime[i].size();j++)
        {
            printf(" %d",prime[i][j]);
        }
        cout<<endl;
    }*/
    int a,b,i,j,x,y,t,k=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        printf("Case %d: ",++k);

        zero();
        a = n;
        flag = 0;
       // printf("yeees\n");
       x = bfs(a);
       if(flag==1)
       {
           printf("%d\n",x);
       }
       else{
        printf("%d\n",-1);
       }
    }

return 0;
}

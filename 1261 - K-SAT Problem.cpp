#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
map<int,int> :: iterator it;
vector<int>v[110];
int visited[110];
int main()
{
//   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j=0,x=0,y=0,flag,sum,l,k;
    string s[110],s2;
    char str;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        getchar();
        mp.clear();
        memset(visited,0,sizeof(visited));
        for(i=0; i<=105; i++)
            v[i].clear();

        for(i=1; i<=m; i++)
        {
            mp[i] = 0;
        }

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=k; j++)
            {
                scanf("%d",&a);
                if(a>0)
                    v[i].push_back(a);
                else
                    v[i].push_back(a);

            }

        }
        getchar();

       /* printf("%d %d %d\n",n,m,k);
        for(i=1; i<=n; i++)
        {
            printf("%d : ",i);
            for(j=0; j<v[i].size(); j++)
            {
                printf(" %d",v[i][j]);
            }
            printf("\n");
        }*/

      scanf("%d",&x);

      for(i=1;i<=x;i++)
      {
        scanf("%d",&a);
        mp[a] = 1;
      }
      /*  for(it = mp.begin(); it!=mp.end(); it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;*/
        for(i=1; i<=n; i++)
        {
            for(j=0; j<v[i].size(); j++)
            {
                a = v[i][j];
                if(a<0&&mp[-a]==0)
                {
                    //printf("j = %d \n",j);
                    visited[i] = 1;
                    break;
                }
                else if(a>0&&mp[a]==1)
                {

                    visited[i] = 1;
                    break;
                }
            }
        }

        flag = 0;
        for(i=1; i<=n; i++)
        {
            if(visited[i]==0)
            {
                flag = 1;
                break;
            }
        }
       // for(i=1;i<=n;i++){
       //     printf("%d %d\n",i,visited[i]);
      //  }

        if(flag==0)
        {
            printf("Case %d: Yes\n",++y);
        }
        else
        {
            printf("Case %d: No\n",++y);
        }

    }









    return 0;
}

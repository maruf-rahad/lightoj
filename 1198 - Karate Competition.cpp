#include<bits/stdc++.h>
using namespace std;
int ara[100];
int ara2[100];
int visited[100];
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j,x,y,sum,flag,k = 0,flag2,flag3,c;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(visited,0,sizeof(visited));

        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara2[i]);
        }
        sort(ara+1,ara+n+1);
        sort(ara2+1,ara2+n+1);
        sum = 0;

        for(i=1;i<=n;i++)
        {
            flag = 0;
            flag2 = 0;
            flag3 = 0;
            a = 0;
            b = 0;
            c = 0;
            for(j=1;j<=n;j++)
            {
                if(ara[i]>ara2[j]&&visited[j]==0)
                {
                    a = j;
                    flag = 1;
                }
                if(ara[i]>ara2[j]&&visited[j]==2)
                {
                    c = j;
                    flag3 = 1;
                }
                if(ara[i]==ara2[j]&&visited[j]==0)
                {
                    b = j;
                    flag2 = 1;
                }


            }

          //  printf("\n%d %d\n%d %d\n%d %d\n\n",flag,a,flag3,c,flag2,b);

            if(flag==1)
            {
             //   printf("jog 2\n");
                visited[a] = 1;
                sum+=2;
            }
            else if(flag3==1)
            {
             //   printf("draw marse \n");
                sum+=1;
                visited[c] = 1;
            }
            else if(flag2==1)
            {
              //  printf("draw korse \n");
                sum+=1;
                visited[b] = 2;
            }
            else{
                for(j=n;j>=1;j--)
                {
                    if(visited[j]==0){
                        visited[j] = 1;
                        break;
                    }
                }
            }

        }

        printf("Case %d: %d\n",++k,sum);

    }













return 0;
}

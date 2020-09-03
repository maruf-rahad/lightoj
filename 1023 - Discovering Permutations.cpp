#include<bits/stdc++.h>
using namespace std;
char ch[30];
char str[30];
int used[30];
int sum,flag;
void sett()
{
    for(int i=1;i<=26;i++)
    {
        ch[i] = 'A'+i-1;
    }
}

void permute(int n,int att,int m)
{
    if(sum == m||flag==1)
    {
        flag = 1;
        return;
    }
    if(att==n+1)
    {
        sum++;
        for(int i=1;i<=n;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0&&flag==0)
        {
            str[att] = ch[i];
            used[i] = 1;
            permute(n,att+1,m);
            used[i] = 0;
        }
    }



}
int main()
{
    sett();
    int i,j,a,b,x,y,t,n,m,k = 0;;

    scanf("%d",&t);
    while(t--)
    {
        memset(used,0,sizeof(used));
        scanf("%d %d",&n,&m);
        sum = 0;
        flag = 0;
        printf("Case %d:\n",++k);
        permute(n,1,m);
    }














return 0;
}

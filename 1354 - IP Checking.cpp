#include<bits/stdc++.h>
using namespace std;
vector<int>v[9];
vector<int>v2[9];
int inp[9];
int main()
{
    int a,b,c,d,n,i,j,x,k = 0;
    char ch;
    scanf("%d%c",&n,&ch);

    while(n--)
    {
        for(i=0;i<9;i++)
        {
            v[i].clear();
            v2[i].clear();
        }

        scanf("%d%c%d%c%d%c%d%c",&inp[1],&ch,&inp[2],&ch,&inp[3],&ch,&inp[4],&ch);
        scanf("%d%c%d%c%d%c%d%c",&inp[5],&ch,&inp[6],&ch,&inp[7],&ch,&inp[8],&ch);

    for(i=1;i<=4;i++)
    {
        a = inp[i];

        while(a!=0)
        {
            x = a%2;
            v[i].push_back(x);
            a = a/2;
        }
        while(v[i].size()!=8)v[i].push_back(0);

    }
    j = 1;
    for(i=5;i<=8;i++)
    {

        a = inp[i];
        while(a!=0)
        {
            x = a%10;
            v2[j].push_back(x);
            a = a/10;
        }
        while(v2[j].size()!=8)
        {
            v2[j].push_back(0);
        }
        j++;

    }
    int flag = 0;

    for(i=1;i<=4;i++)
    {
        for(j=0;j<8;j++)
        {
            if(v[i][j]!=v2[i][j])
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)break;
    }

    if(flag==1)
    {
        printf("Case %d: No\n",++k);
    }
    else
    {
        printf("Case %d: Yes\n",++k);
    }







    }













return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,ind;
};

node ara[1010];

void precal()
{
      int i,j;

    for(i = 1;i<=1000;i++)
    {
        ara[i].ind = i;
        for(j=i;j<=1000;j+=i)
        {
            ara[j].val++;
        }
    }
}
bool cmp(node a,node b)
{
    if(a.val>b.val)
    {
        return false;
    }
    else if(a.val==b.val)
    {
        if(a.ind<b.ind)return false;
    }

    return true;
}

int main()
{
    precal();
    sort(ara+1,ara+1001,cmp);

    int i,j,n,m,a,b,x,y,t,k=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++k,ara[n].ind);
    }
















return 0;
}

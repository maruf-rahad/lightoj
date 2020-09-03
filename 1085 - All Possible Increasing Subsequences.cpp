#include<bits/stdc++.h>
using namespace std;
#define mx 100100
int ara[mx];
int ara2[mx];
int visited[mx];
itn tree[mx*4];
void zero(int n)
{
    for(i=1;i<=n;i++)
    {
        ara2[i] = 0;
        visited[i] =  0;
    }
}

void build(int node,int b,int e,int i,int j,int x)
{
    if(b>j||e<i)return 1e9;
    if(b>=i&&e<=j&&x>tree[node])
    {
        return tree[node];
    }


    int mid = (b+e)>>1;
    int left = node<<1;
    int right = node<<1|1;

    int r1 = build(left,b,mid,i,j);
    int r2 = build(right,mid+1,e,i,j);
    return min(r1,r2);
}

int main()
{
    int n,m,a,b,i,j,x,y,t;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=n-1;i>=1;i--)
        {
            ara[i] = ara[i]+ara[i+1];
        }


    }













retrun 0;
}

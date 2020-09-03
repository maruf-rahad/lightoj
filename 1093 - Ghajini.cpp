#include<bits/stdc++.h>
using namespace std;
#define mxx 200010
int ara[mxx];
struct nod{
    int xx,yy;
};
nod tree[mxx*4];

void build(int node,int b,int e)
{

    if(b==e)
    {
        tree[node].xx = ara[b];
        tree[node].yy = ara[b];
         return ;
    }

    int mid = (b+e)/2;
    int left = node*2;
    int right = node*2+1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].xx = max(tree[left].xx,tree[right].xx);
    tree[node].yy = min(tree[left].yy,tree[right].yy);
}

int query(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)return -9;

    if(b>=i&&e<=j)return tree[node].xx;

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int r1 = query(left,b,mid,i,j);
    int r2 = query(right,mid+1,e,i,j);
    return max(r1,r2);

}

int minquery(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)return 1e9;
    if(b>=i&&e<=j)return tree[node].yy;

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int r1 = minquery(left,b,mid,i,j);
    int r2 = minquery(right,mid+1,e,i,j);

    return min(r1,r2);




}
int main()
{
   // freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j,x,y,sum,mx,k=0,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        mx = -1;
        for(i=1;i+m-1<=n;i++)
        {
            x = query(1,1,n,i,i+m-1);
            y = minquery(1,1,n,i,i+m-1);
            d = abs(x-y);
            mx = max(mx,d);
        }
        printf("Case %d: %d\n",++k,mx);

    }










return 0;
}

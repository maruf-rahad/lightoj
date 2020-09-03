#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define maxi 1e8
int  ara[1000];
int tree[4000];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = ara[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = min(tree[left],tree[right]);


}

int query(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)
        return maxi;

    if(b>=i&&e<=j)
        return tree[node];

        int left = node*2;
        int right = node*2+1;
        int mid = (b+e)/2;

        int p1 = query(left,b,mid,i,j);
        int p2 = query(right,mid+1,e,i,j);

        return min(p1,p2);

}
int main()
{
    int t,n,m,a,b,i,j,x,k=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(tree,maxi,sizeof(tree));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }

        init(1,1,n);
        printf("Case %d:\n",++k);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            x = query(1,1,n,a,b);
            printf("%d\n",x);
        }

    }










return 0;
}

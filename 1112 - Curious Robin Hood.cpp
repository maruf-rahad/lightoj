#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ara[mx];
int tree[mx*4];

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

    tree[node] = tree[left]+tree[right];

}
void updatezero(int node, int b, int e, int i, int j,int newvalue)
{
    if(b>j||e<i)
        return;

    if(b==e)
    {
        tree[node] =  newvalue;
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    updatezero(left,b,mid,i,j,newvalue);
    updatezero(right,mid+1,e,i,j,newvalue);

    tree[node] = tree[left]+tree[right];
}
void updateadd(int node,int b,int e,int i,int j,int newvalue)
{
    if(b>j||e<i)
        return;
    if(b==e)
    {
        tree[node] = tree[node]+newvalue;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    updateadd(left,b,mid,i,j,newvalue);
    updateadd(right,mid+1,e,i,j,newvalue);

    tree[node] = tree[left]+tree[right];

}
int query(int node,int b,int e,int i,int j)
{

    if(b>j||e<i)return 0;

    if(b>=i&&e<=j)
    {
        return tree[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
  //  freopen("output.txt","w",stdout);
    int t,n,m,i,j,a,b,x,y,c,k=0;

    scanf("%d",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",++k);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a);
            if(a==1)
            {
                scanf("%d",&b);
                x = query(1,1,n,b+1,b+1);
                printf("%d\n",x);
                updatezero(1,1,n,b+1,b+1,0);
            }
            else if(a==2)
            {
                scanf("%d %d",&b,&c);
                updateadd(1,1,n,b+1,b+1,c);
            }
            else if(a==3)
            {
                scanf("%d %d",&a,&b);
                x = query(1,1,n,a+1,b+1);

                printf("%d\n",x);
            }
        }
    }











return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define mx 200000
int ara[mx];

struct node{
    int capacity;
    int ase;
    int val;
};
node tree[mx*4];

void zero(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        ara[n] = 0;
    }
    for(i=0;i<=n*4;i++)
    {
        tree[i].capacity = 0;
        tree[i].ase = 0;
        tree[i].val = 0;
    }
}

void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].val = ara[b];
        if(ara[b]!=0)
        {
            tree[node].capacity = 1;
            tree[node].ase = 1;
        }
    return ;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].ase = tree[left].ase+tree[right].ase;
    tree[node].capacity = e-b+1;

}
int main()
{
    int t,n,m,a,b,i,j,x,y,sum;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        zero(n+m+10);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }

        build(1,1,n+m+5);

        for(i=1;i<=30;i++)
        {
            printf("%d %d %d\n",i,tree[i].capacity,tree[i].ase);
        }
    }












return 0;
}

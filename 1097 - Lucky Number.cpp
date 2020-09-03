#include<bits/stdc++.h>
using namespace std;
#define mx 1429600
int tree[mx*4];
int flag;
void init(int node,int b,int e)
{
    if(b==e&&b%2==0)return;
    if(b==e)
    {
        tree[node] = 1;
        return;
    }
    int mid = (b+e)>>1;
    int left = node<<1;
    int right = node<<1|1;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left]+tree[right];
}
void build(int node,int b,int e,int num,int carry)
{

    if(flag==1||tree[node]+carry<num)return;

    if(flag==0&&b==e&&carry+tree[node]==num)
    {
        flag = 1;
        tree[node] = 0;
        return;
    }
    int mid = (b+e)>>1;
    int left = node<<1;
    int right = node<<1|1;

    if(flag==0)
        build(left,b,mid,num,carry);
    if(flag==0)
        build(right,mid+1,e,num,tree[left]+carry);

        tree[node] = tree[left]+tree[right];
}
int query(int node,int b,int e,int num,int carry)
{

    if(flag==1||tree[node]+carry<num)
    {
        return -1;
    }
    if(flag==0&&b==e&&tree[node]+carry==num)
    {
        flag  = 1;
        return b;
    }
    int mid = (b+e)>>1;
    int left = node<<1;
    int right = node<<1|1;

    int  r1 = query(left,b,mid,num,carry);
    int r2 = query(right,mid+1,e,num,carry+tree[left]);

    if(r1==-1)return r2;
    else return r1;


}
void make()
{

    for(int i=2;i<=mx;i++)
    {
        flag=0;
        int x = query(1,1,mx,i,0);
        if(x==-1)return;
        for(int j=x;j<=mx;j+=x-1)
        {
            flag=0;
            build(1,1,mx,j,0);
            if(flag==0)break;
        }
    }
}
int main()
{

    init(1,1,mx);
    int i,j,a,b,x,y,n,m,t,k=0;
    make();

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        flag = 0;
        x = query(1,1,mx,m,0);
        printf("Case %d: %d\n",++k,x);
    }
















return 0;
}

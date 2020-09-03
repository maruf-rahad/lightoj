#include<bits/stdc++.h>
using namespace std;
#define mx 100010
int tree[mx*4];
void zero(int n)
{
    for(int i=0;i<=n*4+3;i++)
    {
        tree[i] = 0;
    }
}
void update(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)
        return;

    if(b>=i&&e<=j)
    {
        tree[node]++;
        return;
    }
    int left = node<<1;
    int right = (node<<1)+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}
int query(int node,int b,int e,int i,int j,int carry)
{
    if(b>j||e<i)
        return 0;
    if(b>=i&&e<=j)
    {
        return tree[node]+carry;
    }
    int left = node<<1;
    int right = (node<<1)+1;
    int mid = (b+e)/2;

    int r1 = query(left,b,mid,i,j,tree[node]+carry);
    int r2 = query(right,mid+1,e,i,j,tree[node]+carry);

    return max(r1,r2);

}
int main()
{
    char ch;
    string s,s2;
    int k = 0,n,m,a,b,i,j,x,y,t;
    scanf("%d",&t);
    while(t--)
    {
        s.clear();
        s = " ";
        cin>>s2;
        s+=s2;
        n = s.size();

        zero(n);

        scanf("%d",&m);
        getchar();
        printf("Case %d:\n",++k);
        while(m--)
        {
            scanf("%c",&ch);
            if(ch=='I')
            {
                scanf("%d %d",&a,&b);
                getchar();
                update(1,1,n,a,b);
            }
            else if(ch=='Q')
            {
                scanf("%d",&a);
                getchar();
                x = query(1,1,n,a,a,0);
                if(x%2==0)
                {
                    cout<<s[a]<<endl;
                }
                else{
                    if(s[a]=='0')
                    {
                        cout<<"1"<<endl;
                    }
                    else{
                        cout<<"0"<<endl;
                    }

                }
            }
        }




    }









return 0;
}

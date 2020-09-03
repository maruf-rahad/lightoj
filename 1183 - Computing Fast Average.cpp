#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef long long ll;

ll v[MAX+10];
ll tree[MAX*4];
ll prop[MAX*4];                     // sum of values

void init(int pos, int l, int r)
{
    tree[pos] = 0;
    prop[pos] = -1;
    if(l == r)
        return;

    int mid = (l+r)>>1;
    init(pos<<1, l, mid), init(pos<<1|1, mid+1, r);
}
// pos, l, r : node values
// L, R : update range

void propagate(int pos, int l, int r)
{
    if(l == r or prop[pos] == -1)
        return;

    int mid = (l+r)>>1;

    tree[pos<<1] = (mid-l+1)*prop[pos];
    tree[pos<<1|1] = (r-mid)*prop[pos];

    prop[pos<<1] = prop[pos<<1|1] = prop[pos];
    prop[pos] = -1;
}

ll update(int pos, int l, int r, int L, int R, ll val)
{
    if(r < L or R < l)
        return tree[pos];

    propagate(pos, l, r);
  //  printf("pos - %d %lld l - %d %lld r %d %lld\n",pos,tree[pos],pos>>1,tree[pos>>1],pos>>1|1,tree[pos>>1||1]);
    if(L <= l and r <= R)
    {
        tree[pos] = (r-l+1)*val;
        prop[pos] = val;
        return tree[pos];
    }

    int mid = (l+r)>>1;
    return tree[pos] = update(pos<<1, l, mid, L, R, val) + update(pos<<1|1, mid+1, r, L, R, val);
}

ll query(int pos, int l, int r, int L, int R)
{

    if(l>R||r<L)
        return 0;
    propagate(pos,l,r);
    if(l>=L&&r<=R)
    {
        return tree[pos];
    }
    int mid = (l+r)>>1;

    return query(pos<<1,l,mid,L,R)+query(pos<<1|1,mid+1,r,L,R);
}

void dbg(int pos, int l, int r)
{
    //tree[pos] = prop[pos] = 0;
    cout << pos << " : " << l << " - " << r << " = " << tree[pos] << ", " << prop[pos] << endl;
    if(l == r)
        return;

    int mid = (l+r)>>1;
    dbg(pos<<1, l, mid), dbg(pos<<1|1, mid+1, r);
}

int main()
{
    //freopen("output.txt","w",stdout);
    ll t,q,n,l,r,a,val,i,x,y,z;
    scanf("%lld", &t);

    for(int Case = 1; Case <= t; ++Case)
    {
        scanf("%lld%lld", &n, &q);
        init(1,1,n);
      //  memset(tre)
          printf("Case %d:\n",Case);
        for(i=1; i<=q; i++)
        {
            scanf("%lld",&a);
            if(a==1)
            {
                scanf("%lld %lld %lld",&l,&r,&val);
                update(1,1,n,l+1,r+1,val);
            }
            else
            {
                scanf("%lld %lld",&l,&r);
                x = query(1,1,n,l+1,r+1);
                y = __gcd(x,r-l+1);
                if(x%(r-l+1)==0)
                {
                    printf("%lld\n",x/(r-l+1));
                }
                else{
                    printf("%lld/%lld\n",x/y,(r-l+1)/y);
                }
            }
           // dbg(1,1,n);
        }
    }































    return 0;
}

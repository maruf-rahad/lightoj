#include<bits/stdc++.h>
using namespace std;
#define F            first
#define S            second
#define PB           push_back
#define MP           make_pair
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF9 2147483647
#define INF18 9223372036854775806
#define ll long long
#define ull unsigned long long
#define pp pair<int,int>
#define ppp pair<int,pp >
#define mapii map<int,int>
#define mapll map<ll,ll>
#define mapsi map<string,int>
#define mapss map<string,string>

char Uplowch(char ch)
{
    if(ch >= 'A' &&  ch <= 'Z')
        ch += 32;
    return ch;
}
char Lowupch(char ch)
{
    if(ch >= 'a' &&  ch <= 'z')
        ch -= 32;
    return ch;
}

int ara[100010];
int ans[100010];
int frequency[100010];
vector<ppp>v;
int block;

bool cmp(ppp a,ppp b)
{
    if(a.F/block==b.F/block)
    {
        if(a.S.F>b.S.F)
            return false;
        return  true;
    }
    else if(a.F/block>b.F/block)
        return false;
    else
        return true;
}

void mosAlgo()
{
    int cnt = 0;
    int lp=0,rp=-1;
    for(int i=0; i<v.size(); i++)
    {
        int L = v[i].F;
        int R = v[i].S.F;

        while(lp>L)
        {
            --lp;
            frequency[ara[lp]]++;
            if(frequency[ara[lp]]==1)
                cnt++;

        }
        while(rp<R)
        {
            rp++;
            frequency[ara[rp]]++;
            if(frequency[ara[rp]]==1)
                cnt++;
        }
        while(lp<L)
        {
            frequency[ara[lp]]--;
            if(frequency[ara[lp]]==0)
                cnt--;
            lp++;

        }
        while(rp>R)
        {
            frequency[ara[rp]]--;
            if(frequency[ara[rp]]==0)
                cnt--;
            --rp;
        }

        ans[v[i].S.S] = cnt;

    }

}

int main()
{
   // freopen("input.txt","r",stdin);

  // freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j,k=0;

    scanf("%d",&t);
    while(t--)
    {
        memset(frequency,0,sizeof(frequency));
        scanf("%d %d",&n,&m);
        v.clear();
        block = sqrt(n);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            v.push_back({a,{b,i}});
        }

        sort(v.begin(),v.end(),cmp);

        mosAlgo();
        printf("Case %d:\n",++k);

        for(i=1;i<=m;i++)
        {
            printf("%d\n",ans[i]);
        }

    }










    return 0;
}

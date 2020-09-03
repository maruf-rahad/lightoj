#include<bits/stdc++.h>
using namespace std;
#define mx 200
int ara[mx+20];
vector<int>v;
int sz;
void sieve()
{
    v.push_back(2);
    for(int i=3; i<=mx; i+=2)
    {

        if(ara[i]==0)
        {
            v.push_back(i);
            for(int j=i*i; j<=mx; j+=(2*i))
                ara[j] = 1;
        }
    }
}

void fact(int n)
{
    int i,sum,a,j,flag=0;
    for(i=0; i<sz&&v[i]<=n; i++)
    {
        sum = 0;
        a = v[i];
        for(j=a;j<=n;j=j*a)
        {
            sum+=(n/j);
        }
        if(flag==1)printf(" *");
        flag = 1;
        printf(" %d (%d)",v[i],sum);
    }
}
int main()
{
    sieve();
    sz = v.size();

    int t,n,m,i,j,k=0,a;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        printf("Case %d: %d =",++k,a);
        fact(a);
        printf("\n");
    }













    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define mx 10000000
#define ll long long
int ara[mx+10];
vector<int>v;

void sieve()
{
    ll i,j;
    for(i=4;i<=mx;i+=2)ara[i] = 1;

    v.push_back(2);
    for(i=3;i<=mx;i+=2)
    {
        if(ara[i]==0)
        {
            v.push_back(i);
            for(j=i*i;j<=mx;j+=(2*i))ara[j] = 1;
        }
    }
}

int main()
{
    sieve();
    for(int i=0;i<=10;i++)printf("%d\n",v[i]);














return 0;
}

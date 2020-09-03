#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define mx 5000100

int ara[mx+10];
ull phi[mx+10];

/*void sieve()
{
    ll i,j;
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
*/
void calphi()
{
    ull i,j;
    phi[1] = 1;
    ara[1] = 1;

    for(i=1;i<=mx;i++)phi[i] = i;

    for(i=2;i<=mx;i++)
    {
        if(ara[i]==0)
        {
            for(j=i;j<=mx;j+=i)
            {
                ara[j] = 1;
                phi[j] = (phi[j]*(i-1))/i;
            }

        }
    }
}

void cumulativephi()
{
    for(int i=2;i<=mx;i++)phi[i] = (phi[i]*phi[i])+phi[i-1];
}
int main()
{
   // freopen("output.txt","w",stdout);
    calphi();
    cumulativephi();
    int a,b;
    int t,k=0;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",++k,phi[b]-phi[a-1]);
    }





return 0;
}

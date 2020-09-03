#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,i,j,k=0,sum,n,a;
    scanf("%lld",&t);
    while(t--)
    {
        string s;
        cin>>s>>n;
        n = abs(n);
        sum = 0;
        a = 0;
        if(s[0]=='-')a++;

        for(i=a;i<s.size();i++)
        {
            sum = ((sum*10)%n+(s[i]-'0'))%n;
        }
        printf("Case %lld: ",++k);
        if(sum%n==0)
        {
            printf("divisible\n");
        }
        else{
            printf("not divisible\n");
        }
    }













return 0;
}

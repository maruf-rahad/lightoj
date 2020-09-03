#include<bits/stdc++.h>
using namespace std;
int ara[10005];
int a, b, c, d, e, f,x;
int fn( int n ) {
    if(n<0)return 0;
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(ara[n]!=0)return ara[n];

    x = (fn(n-1)% 10000007 + fn(n-2)% 10000007 + fn(n-3)% 10000007 + fn(n-4)% 10000007 + fn(n-5)% 10000007 + fn(n-6)% 10000007)% 10000007;
    ara[n] = x;

    return ara[n];
}
int main() {
    int n, caseno = 0, cases,i;
    scanf("%d", &cases);
    while( cases-- ) {
            for(i=0;i<=n+1;i++)ara[i] = 0;

        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

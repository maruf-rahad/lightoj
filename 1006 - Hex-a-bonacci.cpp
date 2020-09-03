#include<bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;
int ara[10005];
int fn() {

    ara[0] = a;
    ara[1] = b;
    ara[2] = c;
    ara[3] = d;
    ara[4] = e;
    ara[5] = f;

    for(int i=6;i<=10002;i++)
    {
        ara[i] = (ara[i-1]% 10000007+ara[i-2]% 10000007+ara[i-3]% 10000007+ara[i-4]% 10000007+ara[i-5]% 10000007+ara[i-6]% 10000007)% 10000007;
    }

}
int main() {
   // freopen("output.txt","w",stdout);
    int n, caseno = 0, cases,i;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        fn();




        printf("Case %d: %d\n", ++caseno, ara[n] % 10000007);
    }
    return 0;
}

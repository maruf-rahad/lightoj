#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
    ull a,b,i,j,x,y,n,m,k = 0,t;

    cin>>t;
    while(t--)
    {
        cin>>m>>n;

        x = (n/3)*2;
        if(n%3==2)
            x++;

        y = ((m-1)/3)*2;

        if((m-1)%3==2)
            y++;
        cout<<"Case "<<++k<<": "<<(x-y)<<endl;

    }











    return 0;
}

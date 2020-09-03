#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,a,b,i,j=0;
    scanf("%d",&n);

    while(n--)
    {
        cin>>s;
        int flag = 0;



        for(i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i-1])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Case %d: Yes\n",++j);
        }
        else{
            printf("Case %d: No\n",++j);
        }
    }







return 0;
}

#include<bits/stdc++.h>
using namespace std;
map<int,string>mp;
map<int,int>mp2;
map<int,int> :: iterator it;
int main()
{
    //freopen("input.txt","r",stdin);
    int t,n,m,i,j,x,y,sum,a,b,c,k=0;
    string s;

    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        mp2.clear();
        scanf("%d",&n);
        for(i=1; i<=n; i++)
        {
            cin>>s>>a>>b>>c;
            x = a*b*c;
            mp[x] = s;
            mp2[x]++;
        }
        printf("Case %d: ",++k);
        if(mp2.size()==1)
        {
            printf("no thief\n");
        }
        else
        {
            int mx = -9;
            int mn = 99999999;
            for(it = mp2.begin(); it!=mp2.end(); it++)
            {
                a = it->first;
                if(a>mx)
                {
                    mx = a;
                }
                if(a<mn)
                {
                    mn = a;
                }
            }

            cout<<mp[mx]<<" took chocolate from "<<mp[mn]<<endl;
        }
    }










    return 0;
}

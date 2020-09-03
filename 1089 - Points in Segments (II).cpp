#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
vector<int>v2;
map<int,int>mp;
int main()
{
    int n,m,a,b,i,j,x,y,t,k=0;

    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        mp.clear();
        v2.clear();

        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            v.push_back({a,-1});
            v.push_back({b,1});
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a);
            v.push_back({a,0});
            v2.push_back(a);
        }
        sort(v.begin(),v.end());

        int sum = 0;

        int s = v.size();
        for(i=0;i<s;i++)
        {
            if(v[i].second==1)sum--;
            if(v[i].second==-1)sum++;
            if(v[i].second==0)
            {
                mp[v[i].first] = sum;
            }
        }
        printf("Case %d:\n",++k);
        for(i=0;i<v2.size();i++)
        {
            printf("%d\n",mp[v2[i]]);
        }


    }











return 0;
}

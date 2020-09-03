#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int n,a,b,i,j,x,y,flag,t,m,k = 0;

    char ch,str;

    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d%c",&a,&str);
            v.push_back(a);
        }

        for(j=1;j<=m;j++)
        {
            scanf("%c%c",&ch,&str);
            if(ch!='R')
            {
                scanf("%d%c",&a,&str);
            }
            if(ch=='S')
            {
                for(i=0;i<n;i++)
                {
                    v[i] = v[i]+a;
                }
            }
            else if(ch=='M')
            {
                for(i=0;i<n;i++)
                {
                    v[i] = v[i]*a;
                }
            }
            else if(ch=='D')
            {
                for(i=0;i<n;i++)
                {
                    v[i] = v[i]/a;
                }
            }
            else if(ch=='P')
            {
                scanf("%d%c",&b,&str);
                swap(v[a],v[b]);
            }
            else if(ch=='R')
            {
                for(i=0;i<n/2;i++)
                {
                    swap(v[i],v[n-i-1]);
                }
            }



    }
        printf("Case %d:\n%d",++k,v[0]);
        for(i=1;i<v.size();i++)
        {
            printf(" %d",v[i]);
        }
        printf("\n");
    }







return 0;
}

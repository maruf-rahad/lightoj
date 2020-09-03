#include<bits/stdc++.h>
using namespace std;
int ara[50];
int ara2[50];
int main()
{
    int t,n,m,a,b,i,j,x,y,flag,k=0;
    string ch,ch2;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(ara,0,sizeof(ara));
        memset(ara2,0,sizeof(ara2));
        getline(cin,ch);
        getline(cin,ch2);
        for(i=0;i<ch.size();i++)
        {
            if(ch[i]>='A'&&ch[i]<='Z')ch[i]+=32;

            a = ch[i]-'a'+1;
            if(a>=1&&a<=26)
                ara[a]++;

        }
        for(i=0;i<ch2.size();i++)
        {
            if(ch2[i]>='A'&&ch2[i]<='Z')ch2[i]+=32;

            a = ch2[i]-'a'+1;
            if(a>=1&&a<=26)
                ara2[a]++;

        }
        flag = 0;
        for(i=1;i<=26;i++)
        {
            if(ara[i]!=ara2[i])
            {
                flag = 1;
                break;
            }
        }

        if(flag==0)
        {
            printf("Case %d: Yes\n",++k);
        }
        else{
            printf("Case %d: No\n",++k);
        }
    }
















return 0;
}

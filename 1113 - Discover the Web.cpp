#include<bits/stdc++.h>
using namespace std;
stack<string>bk;
stack<string>fw;
void visit()
{
    string s2;
    cin>>s2;
    cout<<s2<<endl;
    bk.push(s2);
    while(!fw.empty())fw.pop();
}
void backk()
{
    string s,s2;
    if(bk.size()==1)
    {
        printf("Ignored\n");
    }
    else
    {

        s = bk.top();
        fw.push(s);
        bk.pop();
        if(bk.empty())
        {
            printf("Ignored\n");
        }
        else
        {
            cout<<bk.top()<<endl;
        }
    }
}
void forwardd()
{
    string s,s2;
    if(fw.empty())
    {
        printf("Ignored\n");
    }
    else
    {
        s = fw.top();
        cout<<s<<endl;
        bk.push(fw.top());
        fw.pop();
    }




}
void zero()
{
    while(!fw.empty())
    {
        fw.pop();
    }
    while(!bk.empty())
    {
        bk.pop();
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,n,m,a,b,i,j,x,y,k = 0;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++k);
        zero();
        bk.push("http://www.lightoj.com/");
        while(1)
        {
            cin>>s;
            if(s=="QUIT")
                break;
            else if(s=="VISIT")
            {
                visit();
            }
            else if(s=="BACK")
            {
                backk();
            }
            else if(s=="FORWARD")
            {
                forwardd();
            }

        }
    }









    return 0;
}

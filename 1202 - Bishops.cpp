#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("output.txt","w",stdout);
    int t,a,b,i,j,k=0,x,y;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&a,&b,&x,&y);

        printf("Case %d:",++k);
        if(abs(a-x)==abs(b-y))
        {
            printf(" %d\n",1);
        }
        else if(abs(a-b)%2==abs(x-y)%2)
        {
            printf(" %d\n",2);
        }
        else{
            printf(" impossible\n");
        }
    }











return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,i,j = 0,t;
    string s;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int sum = 0;
        printf("Case %d:\n",++j);
        while(n--)
        {
            cin>>s;
            if(s=="donate")
            {
                scanf("%d",&a);
                sum+=a;
            }
            else{

                    printf("%d\n",sum);

            }


        }


    }








return 0;
}

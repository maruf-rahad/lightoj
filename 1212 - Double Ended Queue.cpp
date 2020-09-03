#include<bits/stdc++.h>
using namespace std;
deque<int>dq;
int main()
{
    int n,m,a,b,i,j,x,y,t,sum,k=0;
    char ch[20];

    scanf("%d",&t);
    while(t--)
    {
        while(!dq.empty())dq.pop_back();
        scanf("%d %d",&n,&m);
        sum = 0;

        printf("Case %d:\n",++k);
        for(i=1; i<=m; i++)
        {
            scanf("%s",&ch);
            if((strcmp(ch,"pushLeft")==0)||(strcmp(ch,"pushRight")==0))
            {
                scanf("%d",&a);
            }
            if((sum==n&&strcmp(ch,"pushLeft")==0)||(sum==n&&strcmp(ch,"pushRight")==0))
            {
                printf("The queue is full\n");
            }
            else if((sum==0&&strcmp(ch,"popLeft")==0)||(sum==0&&strcmp(ch,"popRight")==0))
            {
                printf("The queue is empty\n");
            }
            else if(strcmp(ch,"pushLeft")==0)
            {
                printf("Pushed in left: %d\n",a);
                sum++;
                dq.push_front(a);
            }
            else if(strcmp(ch,"pushRight")==0)
            {
                sum++;
                dq.push_back(a);
                printf("Pushed in right: %d\n",a);
            }
            else if(strcmp(ch,"popLeft")==0)
            {
                sum--;
                printf("Popped from left: %d\n",dq.front());
                dq.pop_front();

            }
            else if(strcmp(ch,"popRight")==0)
            {
                sum--;
            printf("Popped from right: %d\n",dq.back());
                dq.pop_back();
            }
        }
    }









    return 0;
}

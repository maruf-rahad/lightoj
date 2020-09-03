#include<bits/stdc++.h>
using namespace std;
int ara[100];
int n;
int lowerbound(int b,int e,int key)
{
    int index = 0;
    while(b<=e)
    {
        int mid = (b+e)/2;

        if(key==ara[mid])
        {
            index = mid;
            e = mid-1;
        }
        else if(key>ara[mid])
        {
            b = mid+1;
        }
        else if(key<ara[mid])
        {
            e = mid-1;
        }
    }

    if(index==0)return b;
    else{
        return index;
    }

}
int upperbound(int b,int e,int key)
{
    int index = 0;
    while(b<=e)
    {
        int mid = (b+e)/2;

        if(key==ara[mid])
        {
            index = mid;
            b = mid+1;
        }
        else if(key<ara[mid])
        {
            e = mid-1;
        }
        else if(key>ara[mid])
        {
            b =  mid+1;
        }
    }
    if(index==0)
    {
        return b-1;
    }
    else return index;
}
int main()
{
    int m,i,j,a,b,x,y,t,k = 0;;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&ara[i]);
        }
        printf("Case %d:\n",++k);
        while(m--)
        {
            scanf("%d %d",&a,&b);
            x = lowerbound(1,n,a);
            if(x>n){
                printf("%d\n",0);
                continue;
            }
            else{
                y = upperbound(1,n,b);
                if(y<1)
                {
                    printf("0\n");
                    continue;
                }
                printf("%d\n",y-x+1);
            }
        }


    }










return 0;
}

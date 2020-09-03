#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("output.txt","w",stdout);
    int n,m,t,a,b,i,j = 0,x,y,r,c;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        printf("Case %d: ",++j);
        if(r==1||c==1)
        {
            printf("%d\n",max(r,c));
        }
        else if(r==2)
        {
            a = c/4;

            b = c%4;
            if(b>=2)
                b = 2;

            a = a*4+b*2;

            printf("%d\n",a);

        }
        else if(c==2)
        {
            a = r/4;

            b = r%4;
            if(b>=2)

                b = 2;

            a = a*4+b*2;

            printf("%d\n",a);

        }
        else{
            double x = ceil((double)r/2)*ceil((double)c/2);
            int y = (r/2)*(c/2);

            printf("%d\n",(int)x+y);




        }


    }






return 0;
}

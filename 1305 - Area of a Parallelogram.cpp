#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,ax,ay,bx,by,cx,cy,dx,dy,a,b,c,d,j = 0,area;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);

        a = bx-ax;
        b = cy-by;
        dx = cx-a;
        dy = ay+b;

        area =abs((ax*by+bx*cy+cx*ay)-(ax*cy+cx*by+bx*ay));


        printf("Case %d: %d %d %d\n",++j,dx,dy,area);




    }



return 0;
}

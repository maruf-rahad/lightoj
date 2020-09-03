#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
   // freopen("output.txt","w",stdout);
        int n,a,b,i,j=0,x,y,z,flag,flag2,flag3,sum;

    scanf("%d",&n);
    while(n--)
    {
        v.clear();

        sum = 0;
        flag = 0;
        flag2 = 0;
        flag3 = 0;

        scanf("%d",&a);

        while(a!=0)
        {
            b = a%2;

            if(b==0)
            {
                flag = 1;
                sum++;
            }

            v.push_back(b);

            a = a/2;
        }
        if(flag==0)
        {
            v.pop_back();
            v.push_back(0);
            v.push_back(1);
        }
        else
        {

            for(i=v.size()-1; i>=1; i--)
            {
                if(v[i]==0&&v[i-1]==1)
                {
                    a = i;
                    flag2 = 1;
                }
            }
            if(flag2==1)
            {
                v[a] = 1;
                v[a-1] = 0;
                for(i=a-2;i>=0;i--)
                {
                    if(v[i]==1)
                    {
                        for(int k = 0;k<i;k++)
                        {
                            if(v[k]==0)
                            {
                                v[k]=1;
                                v[i] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                v.pop_back();
                v.push_back(0);
                v.push_back(1);
                for(i=v.size()-2;i>=0;i--)
                {
                    if(v[i]==1)
                    {
                        for(int k = 0;k<i;k++)
                        {
                            if(v[k]==0)
                            {
                                v[k]=1;
                                v[i] = 0;
                                break;
                            }
                        }
                    }
                }
            }

        }

       sum = 0;

       for(i=0;i<v.size();i++)
       {
           a = v[i]*pow(2,i);
           sum+=a;
       }

        printf("Case %d: %d\n",++j,sum);





    }



    return 0;
}

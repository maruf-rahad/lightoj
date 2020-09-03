#include<bits/stdc++.h>
using namespace std;

struct node
{

    bool endmark;
    node* next[10];
    node()
    {
        endmark = false;
        for(int i=0; i<=9; i++)
            next[i] = NULL;
    }
};
node *root;

bool insert(char* ch,int l)
{
    // printf("%s %d\n",ch,l);
    int i;
    node* curr = root;
    for(i=0; i<l; i++)
    {
        int id = ch[i]-'0';
        if(curr->next[id]==NULL)
        {
            curr->next[id] = new node();
        }
         if(curr->endmark)
            return false;

        curr = curr->next[id];
    }
    if(curr->endmark)
        return false;
    curr->endmark = true;

    for(i=0; i<=9; i++)
    {
        if(curr->next[i]!=NULL)
            return  false;
    }

    return true;
}

void del(node* curr)
{
    for(int i=0;i<=9;i++)
    {
        if(curr->next[i])
        {
            del(curr->next[i]);
        }
    }
    delete(curr);
}

int main()
{
    char ch[11];
    int n,i,t,k = 0;
    scanf("%d",&t);
    while(t--)
    {
        root = new node();
        scanf("%d",&n);
        bool flag = 0;
        int flag2 = 0;
        while(n--)
        {
            scanf("%s",&ch);
            if(!flag2)
            {
                flag =  insert(ch,strlen(ch));;

                if(!flag)
                {
                    flag2 = 1;
                }

            }
        }

            if(flag2==0)
            {
                printf("Case %d: YES\n",++k);

            }
            else
            {
                printf("Case %d: NO\n",++k);
            }

            del(root);

    }













    return 0;
}

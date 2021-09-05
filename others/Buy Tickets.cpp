#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        vector<int>v;
        vector<int>::iterator it;

        int pos,val;

        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&pos,&val);

            v.insert(v.begin()+pos,val);
        }

        for(int i=0; i<v.size(); i++)
        {
            if(i==v.size()-1)
                printf("%d\n",v[i]);
            else
                printf("%d ",v[i]);
        }
    }

    return 0;
}

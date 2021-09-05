#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int a[100010][10];

int convert(char c)
{
    return c-48;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        memset(a,-1,sizeof(a));

        int n;
        cin>>n;

        vector<int>v;
        string s;
        int id=1;

        for(int i=0;i<n;i++)
        {
            cin>>s;

            int row=0;
            for(int j=0;j<s.size();j++)
            {
                int col=convert(s[j]);

                if(a[row][col]==-1)
                {
                    a[row][col]=id;
                    row=id;
                    id++;
                }
                else
                    row=a[row][col];
            }
            v.push_back(row);
        }

        int flag=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<10;j++)
            {
                if(a[v[i]][j]!=-1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }

        if(flag==1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

    return 0;
}

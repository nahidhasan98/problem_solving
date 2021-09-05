#include<bits/stdc++.h>

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

using namespace std;

struct st
{
    int level,times;
};

st counter[10000005];
int a[10000005][2];

int convert(char c)
{
    if(c=='0')
        return 0;
    else if(c=='1')
        return 1;
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

        string s;
        int id=1;

        for(int i=0;i<10000003;i++)
            counter[i].times=0;

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

                    counter[id].level=j+1;
                    counter[id].times++;

                    row=id;
                    id++;
                }
                else
                {
                    counter[a[row][col]].times++;
                    row=a[row][col];
                }
            }
        }

        int res=0,sum=0;

        for(int i=0;i<10000003;i++)
        {
            sum=counter[i].level*counter[i].times;

            res=max(res,sum);
        }

        cout<<res<<endl;
    }

    return 0;
}

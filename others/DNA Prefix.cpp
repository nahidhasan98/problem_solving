#include<bits/stdc++.h>

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

using namespace std;

struct st
{
    int level,times;
};

st counter[2500005];
int a[2500005][4];

int convert(char c)
{
    if(c=='A')
        return 0;
    else if(c=='C')
        return 1;
    else if(c=='G')
        return 2;
    else if(c=='T')
        return 3;
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

        for(int i=0;i<2500003;i++)
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

        for(int i=0;i<2500003;i++)
        {
            sum=counter[i].level*counter[i].times;

            res=max(res,sum);
        }

        cout<<"Case "<<t<<": "<<res<<endl;
    }

    return 0;
}
/*
4
ACGT
ACGTGCGT
ACCGTGC
ACGCCGT

1=4 1
2=4 2
3=3 3
4=2 4
5=1 5
6=1 6
7=1 7
8=1 8
9=1 3
10=1 4
11=1 5
12=1 6
13=1 7
14=1 4
15=1 5
16=1 6
17=1 7
*/

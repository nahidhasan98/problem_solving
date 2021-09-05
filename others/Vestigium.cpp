#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        int a[n][n],sum=0,row=0,col=0;
        set<int>s;

        for(int i=0;i<n;i++)
        {
            s.clear();

            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
                s.insert(a[i][j]);

                if(i==j)
                    sum+=a[i][j];
            }
            if(s.size()!=n)
                row++;
        }
        for(int i=0;i<n;i++)
        {
            s.clear();

            for(int j=0;j<n;j++)
            {
                s.insert(a[j][i]);
            }
            if(s.size()!=n)
                col++;
        }
        cout<<"Case #"<<t<<": "<<sum<<' '<<row<<' '<<col<<endl;
    }

    return 0;
}

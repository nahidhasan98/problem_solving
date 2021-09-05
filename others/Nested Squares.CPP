#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        string s,ss,temp;
        int q,r1,c1,r2,c2,sz,d;

        cin>>s>>q;

        sz=s.size();

        ss=s;
        reverse(ss.begin(),ss.end());

        temp=ss.substr(1);

        ss="";
        ss+='0';
        ss+=s;
        ss+=temp;
        s=ss;

        cout<<"Square "<<t<<":"<<endl;

        for(int k=1;k<=q;k++)
        {
            cin>>r1>>c1>>r2>>c2;

            cout<<"Query "<<k<<":"<<endl;

            //cout<<s<<' '<<r1<<' '<<r2<<' '<<c1<<' '<<c2<<endl;

            for(int i=r1;i<=r2;i++)
            {
                for(int j=c1;j<=c2;j++)
                {
                    if((i+j)==(sz*2))
                        cout<<s[i];
                    else if((i+j)<(sz*2))
                    {
                        d=min(i,j);
                        cout<<s[d];
                    }
                    else if((i+j)>(sz*2))
                    {
                        d=max(i,j);
                        cout<<s[d];
                    }
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}

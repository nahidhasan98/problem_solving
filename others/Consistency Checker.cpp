#include<bits/stdc++.h>

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        vector<string>v;
        string s;

        for(int i=0;i<n;i++)
        {
            cin>>s;

            v.push_back(s);
        }

        sort(v.begin(),v.end());

        int flag=0;

        for(int i=0;i<n-1;i++)
        {
            int sz1=v[i].size();
            int sz2=v[i+1].size();

            if(sz2>=sz1)
            {
                string temp=v[i+1].substr(0,sz1);

                if(v[i]==temp)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            cout<<"Case "<<t<<": NO"<<endl;
        else
            cout<<"Case "<<t<<": YES"<<endl;
    }

    return 0;
}
/*
18
564
46456
435645
345
435
345
435
123
23091234
23498731
4655554
435555
345553
43335
445
23098735
328974
2498
*/

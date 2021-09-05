#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int cpu,mem;
        cin>>cpu>>mem;

        int d,c,m;

        string res;
        vector<string>v;

        for(int i=1; i<=n; i++)
        {
            cin>>d>>c>>m;

            if(c>cpu)
                res="CLE";
            else if(m>mem)
                res="MLE";
            else if(d>0)
                res="WA";
            else
                res="AC";

            v.push_back(res);
        }

        res="";
        int flag=0;

        for(int i=0; i<v.size(); i++)
        {
            if (v[i]!="AC")
            {
                flag=1;

                if(res=="")
                    res=v[i];
            }
        }
        if(flag==0)
            cout<<"AC"<<endl;
        else
            cout<<res<<endl;
    }

    return 0;
}

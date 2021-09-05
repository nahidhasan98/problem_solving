#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        string s,temp="";
        cin>>s;

        int sz=s.size();
        vector<string>v;
        v.push_back(s);

        string ss,last;

        for(int k=sz-1; k>=-1; k--)
        {
            ss=s.substr(0,k+1);
            last=s.substr(k+1);

            cout<<k<<' '<<ss<<' '<<last<<endl;

            for(int i=0; i<last.size(); i++)
            {
                for(int j=0; j<last.size(); j++)
                {
                    temp=last;
                    swap(temp[i],temp[j]);
                    cout<<i<<' '<<j<<" Temp= "<<temp<<endl;
                    string newS=ss+temp;

                    cout<<"New= "<<newS<<endl;

                    v.push_back(newS);
                }
            }
        }
        sort(v.begin(),v.end());
        temp="";

        for(int i=0; i<v.size(); i++)
        {
            if(v[i]!=temp)
            {
                cout<<v[i]<<endl;
                temp=v[i];
            }
        }

        if(t<test)
            cout<<endl;
    }

    return 0;
}

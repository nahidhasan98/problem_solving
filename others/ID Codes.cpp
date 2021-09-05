#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        if(s=="#")
            break;

        int sz=s.size(),flag=0;

        for(int i=1; i<sz; i++)
        {
            if(s[i-1]>=s[i])
                continue;
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"No Successor"<<endl;
        else
        {
            vector<char>v;
            int point;

            for(int i=sz-1; i>=0; i--)
            {
                if(s[i-1]>=s[i])
                {
                    v.push_back(s[i]);
                }
                else
                {
                    v.push_back(s[i]);
                    v.push_back(s[i-1]);
                    point=i-1;
                    break;
                }
            }
            string ss="";
            for(int i=0;i<point;i++)
            {
                ss+=s[i];
            }
            sort(v.begin(),v.end());
            int flag2=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i]==s[point] && v[i+1]!=s[point])
                {
                    ss+=v[i+1];
                    v[i+1]='%';
                    break;
                }
            }
            for(int i=0;i<v.size();i++)
            {
                if(v[i]!='%')
                    ss+=v[i];
            }
            cout<<ss<<endl;
        }
    }

    return 0;
}

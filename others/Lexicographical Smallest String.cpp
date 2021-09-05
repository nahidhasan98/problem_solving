#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string getString(string s,char c,int k)
{
    string returnRes="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    for(int i=1; i<=k; i++)
    {
        string res="";
        int counter=0;

        for(int j=0; j<s.size(); j++)
        {
            if(s[j]==c)
            {
                counter++;
                //cout<<"i="<<i<<" j="<<j<<" s["<<j<<"]="<<s[j]<<" count="<<counter<<endl;

                if(counter==i)
                    res+=s[j];
            }
            else
                res+=s[j];

            //cout<<"building="<<res<<endl;
        }
        //cout<<i<<' '<<res<<endl;

        returnRes=min(returnRes,res);
    }

    return returnRes;
}
int main()
{
    int n,k;

    while(cin>>n>>k)
    {
        string s;
        cin>>s;

        int a[30]= {0};
        char c;

        for(int i=0; i<s.size(); i++)
        {
            c=s[i];

            a[c-'a']++;
        }

        vector<string>v;

        if(k==0 || k==1 || n<k)
            cout<<s<<endl;
        else
        {
            for(int i=0; i<26; i++)
            {
                if(a[i]==k)
                    v.push_back(getString(s,i+'a',k));
            }
            sort(v.begin(),v.end());

            cout<<v[0]<<endl;
        }
    }

    return 0;
}

#include<iostream>
#include<stdio.h>
#include<map>
#include<iomanip>
#include<cstring>
#include<vector>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int n,m;
map<char,int>mp[1005];

void markMap(int ind,string s)
{
    for(int i=0;i<s.size();i++)
        mp[ind][s[i]]=1;
}

bool check(int ind,string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(mp[ind][s[i]]!=1)
            break;

        if(i==s.size()-1)
            return true;
    }
    return false;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        //memset(mp,0,sizeof(mp));

        cin>>n>>m;
        string s;

        for(int i=0;i<n;i++)
        {
            cin>>s;
            markMap(i,s);
        }

        string x,y;

        cout<<"Case "<<t<<":"<<endl;

        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            double xCount=0,yCount=0;
            vector<int>v;

            for(int j=0;j<n;j++)
            {
                if(check(j,x))
                {
                    xCount++;
                    v.push_back(j);

//                    if(check(j,y))
//                        yCount++;
                }
            }
            for(int j=0;j<v.size();j++)
            {
                if(check(v[j],y))
                {
                    yCount++;
                    //v.push_back(j);

//                    if(check(j,y))
//                        yCount++;
                }
            }
            double res=(1.0*yCount)/xCount;
            cout<<fixed<<setprecision(2)<<res<<endl;
        }
    }

    return 0;
}

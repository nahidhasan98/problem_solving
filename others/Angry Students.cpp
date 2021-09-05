#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int k;
        cin>>k;

        string s;
        cin>>s;

        int counter=0,res=0;

        for(int i=0; i<s.size()-1; i++)
        {
            if(s[i]=='A' && s[i+1]=='P')
            {
                counter=0;

                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j]=='P')
                        counter++;
                    else
                    {
                        res=max(res,counter);
                        i=j-1;
                        break;
                    }
                }
                res=max(res,counter);
            }
        }

        cout<<res<<endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int n;

    while(cin>>n)
    {
        string s;
        cin>>s;

        int l=0,r=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='L') l++;
            else if(s[i]=='R') r++;
        }
        cout<<(l+r+1)<<endl;
    }

    return 0;
}

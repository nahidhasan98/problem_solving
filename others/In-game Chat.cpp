#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,counter=0;
        cin>>n;

        string s;
        cin>>s;

        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')')
                counter++;
            else
                break;
        }

        if(counter>(s.size()-counter))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}

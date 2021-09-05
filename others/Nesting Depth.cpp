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
        string s,res="";
        cin>>s;

        int d,hand=0,need;

        for(int i=0; i<s.size(); i++)
        {
            d=s[i]-48;
            //cout<<"hand="<<hand<<' '<<d<<endl;

            if(hand<d)
            {
                need=d-hand;
                for(int j=1; j<=need; j++)
                {
                    res+='(';
                    hand++;
                }
            }
            else if(hand>d)
            {
                need=hand-d;
                for(int j=1; j<=need; j++)
                {
                    res+=')';
                    hand--;
                }
            }
            res+=s[i];
            //cout<<"i="<<i<<' '<<res<<endl;
        }
        for(int j=1; j<=hand; j++)
            res+=')';

        cout<<"Case #"<<t<<": "<<res<<endl;
    }

    return 0;
}

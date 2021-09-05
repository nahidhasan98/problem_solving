#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        int upper=0,lower=0,digit=0,counter=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=65 & s[i]<=90)
                upper=1;
            else if(s[i]>=97 && s[i]<=122)
                lower=1;
            else if(s[i]>=48 && s[i]<=57)
                digit=1;

            if(upper==1 && lower==1 && digit==1)
            {
                counter++;
                upper=0;
                lower=0;
                digit=0;
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}

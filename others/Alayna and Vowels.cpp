#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        int counter=0;
        char c[10]={'A','E','I','O','U','a','e','i','o','u'};

        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<10;j++)
            {
                if(s[i]==c[j])
                {
                    counter++;
                    break;
                }
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}

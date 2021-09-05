#include <bits/stdc++.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s)
{
    string givenHH=s.substr(0,2);
    string middle=s.substr(2,6);
    string format=s.substr(s.size()-2,2);

    string result="";

    if(givenHH=="12" && format=="AM")
        result+="00";
    else if(givenHH!="12" && format!="AM")
    {
        int hour=((givenHH[0]-'0')*10)+(givenHH[1]-'0');

        hour+=12;
        hour%=24;

        string finalHH="";
        while(hour!=0)
        {
            int temp=hour%10;
            hour/=10;

            finalHH+=temp+'0';
        }
        if(finalHH.size()==1)
        {
            finalHH+="0";
        }
        reverse(finalHH.begin(),finalHH.end());
        result+=finalHH;
    } else
    {
        result+=givenHH;
    }
    result+=middle;

    return result;
}

int main()
{
    FI

    string s;
    while(getline(cin, s))
    {
        string result = timeConversion(s);
        cout << result << endl;
    }

    return 0;
}


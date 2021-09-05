#include<bits/stdc++.h>
using namespace std;

string res="";
int fix,non_fix;

int output_input_check(string s)
{
    cout<<s<<"\n";
    cin>>fix>>non_fix;

    if(fix==4)
        return 1;
    else
        return 0;
}

int main()
{
    for(int i=1; i<=4; i++)
    {
        int before=0,flag=0;

        for(int j=0; j<=6; j++)
        {
            string s="";

            if(i==1)
            {
                s+=j+48;
                s+="789";
            }
            else if(i==2)
            {
                s+="7";
                s+=j+48;
                s+="89";
            }
            else if(i==3)
            {
                s+="78";
                s+=j+48;
                s+="9";
            }
            else if(i==4)
            {
                s+="789";
                s+=j+48;
            }

            if(output_input_check(s)==1)
                return 0;

            if(j>0 && (fix>before))
            {
                res+=s[i-1];
                flag=1;
                break;
            }
            else
                before=fix;
        }
        if(flag==0)
        {
            int before=0;

            for(int j=6; j<=9; j++)
            {
                string s="";

                if(i==1)
                {
                    s+=j+48;
                    s+="123";
                }
                else if(i==2)
                {
                    s+="1";
                    s+=j+48;
                    s+="23";
                }
                else if(i==3)
                {
                    s+="12";
                    s+=j+48;
                    s+="3";
                }
                else if(i==4)
                {
                    s+="123";
                    s+=j+48;
                }

                if(output_input_check(s)==1)
                    return 0;

                if(j>6 && (fix>before))
                {
                    res+=s[i-1];
                    flag=1;
                    break;
                }
                else
                    before=fix;
            }
        }
        if(flag==0)
            res+="0";
    }
    cout<<res<<"\n";
    cin>>fix>>non_fix;

    return 0;
}

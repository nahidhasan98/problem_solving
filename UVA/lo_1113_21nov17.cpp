#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,temp;
    string a[110],s;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        int x=0;
        a[0]="http://www.lightoj.com/";

        cout<<"Case "<<i<<":"<<endl;

        while(cin>>s)
        {
            if(s=="VISIT")
            {
                cin>>s;
                x++;
                a[x]=s;
                cout<<a[x]<<endl;

                temp=x;
                while(a[temp+1]!="")
                {
                    a[temp+1]="";
                    temp++;
                }
            }
            else if(s=="BACK")
            {
                if(x==0)
                    cout<<"Ignored"<<endl;
                else
                {
                    x--;
                    cout<<a[x]<<endl;
                }
            }
            else if(s=="FORWARD")
            {
                if(a[x+1]=="")
                    cout<<"Ignored"<<endl;
                else
                {
                    x++;
                    cout<<a[x]<<endl;
                }
            }
            else if(s=="QUIT")
            {
                int z=0;
                while(a[z]!="")
                {
                    a[z]="";
                    z++;
                }

                break;
            }
        }
    }

    return 0;
}


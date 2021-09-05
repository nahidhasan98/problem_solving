#include<bits/stdc++.h>
using namespace std;

unsigned long long decimal(string,int);

int main()
{
    unsigned long long deci;
    int b,v,t[210],q;
    string s[210],ram[2210],var;

    while(cin>>b>>v)
    {
        int count=0,i,j,k,m,x;

        for(int i=1;i<=v;i++)
        {
            cin>>s[i]>>t[i];
            count=count+t[i];
        }

        for(j=1;j<=count;j++)
            cin>>ram[j];

        cin>>q;

        for(k=1;k<=q;k++)
        {
            int start=1;

            cin>>var;
            int x=1,flag=0;

            while(1)
            {
                if(x>v)
                {
                    flag=1;
                    break;
                }
                if(s[x]==var)
                    break;

                start=start+t[x];
                x++;
            }

            string str="";

            if(flag!=1)
            {
                for(m=1;m<=t[x];m++)
                {
                    str=str+ram[start];
                    start++;
                }
                deci=decimal(str,(b*t[x]));
            }

            if(flag==1)
                cout<<var<<"="<<endl;
            else
                cout<<var<<"="<<deci<<endl;
        }
    }

    return 0;
}
unsigned long long decimal(string z,int y)
{
    unsigned long long d=0,p=1;
    int h;

    for(h=y-1;h>=0;h--)
    {
        d=(d+((z[h]-'0')*p));
        p=2*p;
    }

    return d;
}

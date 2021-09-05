#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        long long n,counter=0,temp;
        cin>>n;

        string s="",rs="";

        for(int i=2; i<=n; i++)
        {
            temp=n;
            s="";

            double length=log(temp)/log(i);
            int len=floor(length)+1;
            //cout<<length<<' '<<len<<' ';

            //if(len%2==0)
            {
                while(temp>0)
                {
                    s+=(temp%i)+48;
                    temp/=i;
                }
                rs=s;
                //cout<<" i= "<<i<<" length= "<<s.size()<<endl;

                if(s[0]!='0')
                {
                    reverse(s.begin(),s.end());

                    if(s==rs)
                    {
                        counter++;
                        //cout<<n<<' '<<i<<' '<<s<<endl;
                    }
                }
                //cout<<i<<' '<<counter<<endl;
            }
        }

        cout<<"Case "<<t<<": "<<counter<<endl;
    }

    return 0;
}

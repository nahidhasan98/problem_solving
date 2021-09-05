#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int x;

        for(int i=1;i<=n;i++)
        {
            cin>>x;

            if(x==0)
                cout<<"NULL"<<endl;
            else
            {
                if(x%2==0)
                    cout<<"EVEN ";
                else if(x%2!=0)
                    cout<<"ODD ";

                if(x>0)
                    cout<<"POSITIVE"<<endl;
                else if(x<0)
                    cout<<"NEGATIVE"<<endl;
            }
        }
    }

    return 0;
}


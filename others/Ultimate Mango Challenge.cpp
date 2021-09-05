#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n,l;
        cin>>n>>l;

        int type[n],limit[n];

        for(int i=0;i<n;i++)
            cin>>type[i];
        for(int i=0;i<n;i++)
            cin>>limit[i];

        int counter=0,flag=0;
        for(int i=0;i<n;i++)
        {
            if(limit[i]>=type[i])
                counter+=type[i];
            else
            {
                flag=1;
                break;
            }
        }

        if(counter<=l && flag==0)
            cout<<"Case "<<t<<": Yes"<<endl;
        else
            cout<<"Case "<<t<<": No"<<endl;
    }

    return 0;
}

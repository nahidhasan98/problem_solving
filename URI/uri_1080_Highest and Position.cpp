#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    int d,big=0,pos=0;

    for(int i=1;i<=100;i++)
    {
        cin>>d;

        if(d>big)
        {
            big=d;
            pos=i;
        }
    }
    cout<<big<<endl;
    cout<<pos<<endl;

    return 0;
}



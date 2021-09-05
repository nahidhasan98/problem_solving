#include<iostream>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int a,b;
        cin>>a>>b;

        cout<<"Case "<<t<<": "<<a+b<<endl;
    }

    return 0;
}

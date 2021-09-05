#include<iostream>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        int n;
        cin>>n;

        string s="";

        s+="Harr";

        for(int i=1;i<=n;i++)
            s+='y';

        s+="! Khelbe Hogwarts, Jitbe Hogwarts!";

        cout<<"Case "<<t<<": "<<s<<endl;
    }

    return 0;
}

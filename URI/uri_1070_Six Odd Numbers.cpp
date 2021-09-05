#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;

    while(cin>>x)
    {
        int d=1;

        if(x%2==0)
            x+=1;

        for(int d=1;d<=6;d++)
        {
            cout<<x<<endl;
            x+=2;
        }
    }

    return 0;
}



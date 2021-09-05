#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[6];
    int count=0;

    for(int i=0;i<5;i++)
    {
        cin>>a[i];

        if(a[i]%2==0)
            count++;
    }

    cout<<count<<" valores pares"<<endl;

    return 0;
}

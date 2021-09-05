#include<bits/stdc++.h>
using namespace std;

int main()
{
    float a[6];
    int count=0;

    for(int i=0;i<6;i++)
    {
        cin>>a[i];

        if(a[i]>0)
            count++;
    }

    cout<<count<<" valores positivos"<<endl;

    return 0;
}

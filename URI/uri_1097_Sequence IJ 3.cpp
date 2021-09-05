#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=1,j=7;

    while(i<=9)
    {
        int tmp=j;

        for(int k=1;k<=3;k++)
        {
            cout<<"I="<<i<<" "<<"J="<<j<<endl;
            j--;
        }

        i=i+2;
        j=tmp+2;
    }

    return 0;
}



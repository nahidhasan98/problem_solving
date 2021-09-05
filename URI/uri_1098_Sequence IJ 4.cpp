#include<bits/stdc++.h>
using namespace std;

int main()
{
    double i=0,j=1;

    while(i<=2)
    {
        double tmp=j;

        for(int k=1;k<=3;k++)
        {
            cout<<"I="<<i<<" "<<"J="<<j<<endl;
            j++;
        }

        i=i+.2;
        j=tmp+.2;
    }

    return 0;
}




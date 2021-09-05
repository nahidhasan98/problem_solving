#include<iostream>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        int a[n],res[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        res[n-1]=0;
        int counter=0;

        for(int i=n-2;i>=0;i--)
        {
            if((a[i+1]-a[i])>=2)
                counter++;
            else
                counter=0;

            res[i]=counter+1;
        }

        for(int i=0;i<n;i++)
        {
            if(res[i]!=1)
                cout<<res[i]<<endl;
            else
                cout<<0<<endl;
        }
    }

    return 0;
}


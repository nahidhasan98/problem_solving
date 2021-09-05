#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n;
        cin>>n;

        int a[n],counter1=0,counter2=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
                counter1++;
            else
                counter2++;
        }

        if(counter1%2==0 && counter2%2==0)
            cout<<"YES"<<endl;
        else if(counter1%2==0 && counter2%2!=0)
        {
            if (counter1>=2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }

    return 0;
}

#include<iostream>
using namespace std;

struct st
{
    long long ac,sub;
};

int main()
{
    int n;

    while(cin>>n)
    {
        st a[n];
        long long totalAC=0;
        int counter=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i].ac>>a[i].sub;

            totalAC+=a[i].ac;
        }

        long long avg=totalAC/n,acRate=0;

        for(int i=0;i<n;i++)
        {
            acRate=(a[i].ac*100)/a[i].sub;

            if((a[i].ac>=150) && (a[i].ac>=avg) && (acRate>=70))
                counter++;
        }
        cout<<counter<<endl;
    }

    return 0;
}

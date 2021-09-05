#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    long long n,x;

    while(cin>>n>>x)
    {
        long long low=1,high=n,mid,counter=0;

        while(low!=high)
        {
            mid=(low+high)/2;

            counter++;
            //cout<<low<<' '<<mid<<' '<<high<<' '<<counter<<endl;

            if(mid<x) low=mid+1;
            else if(mid>=x) high=mid;
        }
        cout<<counter<<endl;
    }

    return 0;
}
/*
100 22

1 50 100 1
1 25 50 2
1 13 25 3
14 19 25 4
20 22 25 5
20 21 22 6

6
*/

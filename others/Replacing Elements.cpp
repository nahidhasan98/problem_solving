#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n, d;
        cin >> n >> d;

        int arr[n];
        bool initial = true;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if (arr[i] > d)
                initial = false;
        }
        sort(arr,arr+n);

        if (initial == true || (arr[0] + arr[1] <= d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}

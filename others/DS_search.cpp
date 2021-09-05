#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long n, m, query;
    cin >> n >> m;

    long long arr[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i];
    }

    for ( int i = 0; i < m; i++ ) {
        cin >> query;

        long long low = 0, high = n-1, mid;

        while ( low < high ) {
            mid = ( high + low ) / 2;

            if ( arr[mid] < query ) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        if ( arr[low] == query ) {
            cout << "YES " << low + 1 << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

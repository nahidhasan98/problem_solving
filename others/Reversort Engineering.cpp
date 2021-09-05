#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int reversortSum(int a[], int n) {
    int sum = 0;

    for ( int i = 0; i < n-1; i++ ) {
        int minVal = 99999999;
        int minIdx = 0;

        for ( int j = i; j < n; j++ ) {
            if ( a[j] < minVal ) {
                minVal = a[j];
                minIdx = j;
            }
        }

        for ( int j = i, k = minIdx; j <= i + ((minIdx-i)/2); j++, k-- ) {
            swap(a[j], a[k]);
        }

        sum += minIdx - i + 1;
    }

    return sum;
}
void getPermutation(int a[], int n, int c)
{
    sort(a, a + n);

    int flag = 0;
    do {
        int temp[n];
        for ( int i = 0; i < n; i++ ){
            temp[i] = a[i];
        }

        if ( reversortSum(temp, n) == c ) {
            for ( int i = 0; i < n; i++ ){
                cout << ' ' << a[i];
            }
            cout << endl;
            flag = 1;
            break;
        }
    } while (next_permutation(a, a + n));

    if ( flag == 0 ) {
        cout << " IMPOSSIBLE" << endl;
    }
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n, c;
        cin >> n >> c;

        int a[n];
        for ( int i = 0; i < n; i++ ){
            a[i] = i + 1;
        }

        cout << "Case #" << t << ":";

        getPermutation(a, n, c);
        reversortSum(a, n);
    }

    return 0;
}

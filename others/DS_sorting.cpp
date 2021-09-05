#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

struct student {
    int id, m, e;
};

bool operator < ( student a, student b ) {
    if ( a.m != b.m ) return a.m > b.m;
    else return a.e > b.e;
}

int main() {
    int n;
    cin >> n;

    student arr[n];
    for ( int i = 0; i < n; i++ ) {
        cin >> arr[i].id >> arr[i].m >> arr[i].e;
    }

    sort(arr, arr+n);

    for ( int i = 0; i < n; i++ ) {
        cout << arr[i].id << ' ' << arr[i].m << ' ' << arr[i].e << endl;
    }

    return 0;
}

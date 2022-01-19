#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

struct element {
    int idx;
    long long val;
};

bool operator < ( element a, element b ) {
    return a.val < b.val;
}

priority_queue< element > pq;

void processQuery( long long mod ) {
    while( !pq.empty() ) {
        element temp = pq.top();

        if ( temp.val >= mod ) {
            temp.val %= mod;

            pq.pop();
            pq.push( temp );
        } else break;
    }
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        //take input
        int n;
        cin >> n;

        element temp;
        for ( int i = 0; i < n; i++ ) {
            cin >> temp.val;
            temp.idx = i;

            pq.push( temp );
        }

        //process query
        int q;
        cin >> q;
        long long mod;

        for ( int i = 0; i < q; i++ ) {
            cin >> mod;
            processQuery( mod );
        }

        //printing final array
        long long a[ n ];
        while ( !pq.empty() ) {
            element temp = pq.top();
            a[ temp.idx ] = temp.val;

            pq.pop();
        }

        cout << "Case " << t << ":" << endl;
        for ( int i = 0; i < n; i++ ) {
            cout << a[ i ];

            if ( i != ( n - 1 ) ) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

string source, target;
int srow, scol, erow, ecol;
int visited[ 10 ][ 10 ], dis[ 10 ][ 10 ];
int dx[ 8 ] = { -2, -2, -1, 1,  2, 2, -1,  1 };
int dy[ 8 ] = { -1,  1,  2, 2, -1, 1, -2, -2 };

bool isValid( int r, int c ) {
    if ( r >= 1 && r <= 8 && c >= 1 && c <= 8 ) return true;
    return false;
}

void bfs() {
    queue<pair<int, int> > q;
    q.push( { srow, scol } );
    visited[ srow ][ scol ] = 1;
    dis[ srow ][ scol ] = 0;
    bool flag = false;

    while ( !q.empty() ) {
        pair<int, int> f = q.front();
        q.pop();

        for ( int i = 0; i < 8; i++ ) {
            int nextRow = f.first + dx [ i ];
            int nextCol = f.second + dy [ i ];

            if ( isValid( nextRow, nextCol ) && !visited[ nextRow ][ nextCol ] ) {
                q.push( { nextRow, nextCol } );
                visited[ nextRow ][ nextCol ] = 1;
                dis[ nextRow ][ nextCol ] = dis[ f.first ][ f.second ] + 1;

                if ( nextRow == erow && nextCol == ecol ) {
                    flag = true;
                    break;
                }
            }
        }
        if ( flag ) break;
    }

    cout << "To get from " << source << " to " << target << " takes " << dis[ erow ][ ecol ] << " knight moves." << endl;
}

void getRowCol() {
    srow = source[0] - 96;
    scol = source[1] - '0';

    erow = target[0] - 96;
    ecol = target[1] - '0';
}

int main() {
    while ( cin >> source >> target ) {
        getRowCol();

        memset( visited, 0, sizeof( visited ) );
        memset( dis, 0, sizeof( dis ) );

        bfs();
    }

    return 0;
}

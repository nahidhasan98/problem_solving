#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

vector<int> graph[ 210 ];
int n, visited[ 210 ];

void bfs( int source )
{
    queue<int> q;
    bool flag = true;

    q.push( source );
    visited[ source ] = 0;

    while( !q.empty() ){
        int f = q.front();
        q.pop();

        for( int i = 0; i < graph[ f ].size(); i++ ) {
            int next = graph[ f ][ i ];

            if ( visited[ next ] == -1 ) {
                q.push( next );
                visited[ next ] = !visited[ f ];
            } else {
                if( visited[ next ] == visited[ f ] ) {
                    flag = false;
                    break;
                }
            }
        }

        if( !flag ) break;
    }

    if ( flag ) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
}

int main() {
    while( cin >> n ) {
        if ( n == 0 ) break;

        memset( graph, 0, sizeof( graph ) );
        memset( visited, -1, sizeof(visited ) );

        int l, a, b;
        cin >> l;

        for( int i = 0; i < l; i++ ) {
            cin >> a >> b;

            graph[ a ].push_back( b );
            graph[ b ].push_back( a );
        }

        bfs( 0 );
    }

    return 0;
}

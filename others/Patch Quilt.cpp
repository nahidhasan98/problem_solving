#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int r, c;
char grid[35][35];
bool memory[35][35][18];

int dx[9] = { -1, -1, -1,  0, 0, 0,  1, 1, 1 };
int dy[9] = { -1,  0,  1, -1, 0, 1, -1, 0, 1 };
string dmove[9] = { "UL", "U", "UR", "L", "*", "R", "DL", "D", "DR" };

void resetMemory() {
    for ( int i = 1; i < 35; i++ ) {
        for ( int j = 1; j < 35; j++ ) {
            for ( int k = 1; k < 18; k++ ) {
                memory[i][j][k] = true;
            }
        }
    }
}

bool isValid( int row, int col ) {
    if ( row >=1 && row <= r && col >= 1 && col <= c ) return true;
    return false;
}

vector<string> dfs( int row, int col, string name, int ind ) {
    vector<string>path;
    bool flag = false;
    int neededPathLength = name.size() - ind; //needed length from this position/index

    if ( ind == name.size() ) return path; //reached destination at previous step

    for ( int i = 0; i < 9; i++ ) {
        int tr = row + dx[i], tc = col + dy[i];

        if ( ( isValid( tr, tc ) ) && ( memory[row][col][ind] ) && ( grid[tr][tc] == name[ind] ) ) {
            path = dfs( tr, tc, name, ind+1 );
            path.push_back( dmove[i] );
        }

        if ( path.size() == neededPathLength ) return path;
    }

    memory[row][col][ind] = false;
    path.clear();
    return path;
}

void query( string name ) {
    vector<string>path;
    char start = name[0];
    int i, j, neededPathLength = name.size() - 1;

    for ( i = 1; i <= r; i++ ) {
        for ( j = 1; j <= c; j++ ) {
            if ( start == grid[i][j] ) {
                path = dfs( i, j, name, 1);

                if ( path.size() == neededPathLength ) break;
            }
        }
        if ( path.size() == neededPathLength ) break;
    }

    if ( path.size() == neededPathLength ) {
        cout << name << " found: (" << i << "," << j << ")";

        reverse( path.begin(), path.end() );
        for ( int i = 0; i < path.size(); i++ ) cout << ", " << path[i];
        cout << endl;
    }
    else cout << name << " not found" << endl;
}

void solve() {
    cin >> r >> c;

    for ( int i = 1; i <= r; i++ ) {
        for ( int j = 1; j <= c; j++ ) cin >> grid[i][j];
    }

    int n;
    cin >> n;
    string name;

    for ( int i = 0; i < n; i++ ) {
        cin >> name;

        resetMemory();
        query( name );
    }
}

int main() {
    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        cout << "Case " << t << ":" << endl;
        solve();
    }

    return 0;
}

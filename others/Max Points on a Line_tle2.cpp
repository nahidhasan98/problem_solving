#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

int c = 0;

bool sameLine( pair<int,int>p1, pair<int,int>p2, pair<int,int>p3 ) {
    double left  = ( p1.first - p2.first ) * ( p2.second - p3.second );
    double right = ( p2.first - p3.first ) * ( p1.second - p2.second );

    if ( left == right ) return true;
    else return false;
}

vector<int> getPoints( vector<pair<int,int>>& points, int k ) {
    vector<int>res;

    for( int i = points.size()-1; i >= 0 ; i-- ) {
        for ( int j = i - 1; j >= 0; j-- ) {
            res.clear();
            int counter = 0;

            for ( int k = points.size()-1; k >= 0; k-- ) {
                if ( sameLine( points[ i ], points[ j ], points[ k ] ) ) {
                    counter++;
                    res.push_back( k );
                }
                c++;
            }

            if ( counter == k ) return res;
        }
    }
    return res;
}

int main()
{
    //FO
//    vector<pair<int,int>> points = {{3,1},{4,2},{-1,7},{1,4}};
//    vector<pair<int,int>> points = {{-3,-1},{-1,1},{-2,2},{1,-1},{5,7},{8,10}};
//    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
//    vector<pair<int, int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
//    vector<vector<int>> points = {{2,4},{1,4}};
//    vector<vector<int>> points = {
//        {7,3},{19,19},{-16,3},{13,17},{-18,1},{-18,-17},{13,-3},{3,7},{-11,12},{7,19},{19,-12},{20,-18},{-16,-15},{-10,-15},{-16,-18},
//        {-14,-1},{18,10},{-13,8},{7,-5},{-4,-9},{-11,2},{-9,-9},{-5,-16},{10,14},{-3,4},{1,-20},{2,16},{0,14},{-14,5},{15,-11},{3,11},
//        {11,-10},{-1,-7},{16,7},{1,-11},{-8,-3},{1,-6},{19,7},{3,6},{-1,-2},{7,-3},{-6,-8},{7,1},{-15,12},{-17,9},{19,-9},{1,0},{9,-10},
//        {6,20},{-12,-4},{-16,-17},{14,3},{0,-1},{-18,9},{-15,15},{-3,-15},{-5,20},{15,-14},{9,-17},{10,-14},{-7,-11},{14,9},{1,-1},
//        {15,12},{-5,-1},{-17,-5},{15,-2},{-12,11},{19,-18},{8,7},{-5,-3},{-17,-1},{-18,13},{15,-3},{4,18},{-14,-15},{15,8},{-18,-12},
//        {-15,19},{-9,16},{-9,14},{-12,-14},{-2,-20},{-3,-13},{10,-7},{-2,-10},{9,10},{-1,7},{-17,-6},{-15,20},{5,-17},{6,-6},{-11,-8}
//    };

    int n, k, x, y;
    cin >> n >> k;

    vector<pair<int,int>>points;

    for( int i = 0; i < n; i++ ) {
        cin >> x >> y;
        points.push_back( {x, y} );
    }

    vector<int>v = getPoints(points, k);
    for ( int i = v.size()-1; i >= 0 ; i-- ) {
        cout << points[v[i]].first space points[v[i]].second << endl;
    }
    //  cout << c << endl;

    return 0;
}

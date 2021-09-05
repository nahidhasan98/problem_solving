#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

struct data {
    int id, totalSolved = 0 , score = 0;
    int arr[2000+10];
};

bool operator < ( data a, data b ) {
    if ( a.score != b.score ) return a.score > b.score;
    else if ( a.totalSolved != b.totalSolved ) return a.totalSolved > b.totalSolved;
    else return a.id < b.id;
}

int main() {
    int n, t, p;
    cin >> n >> t >> p;

    data contestant[n];
    int point[p] = { 0 };

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < t; j++ ) {
            cin >> contestant[i].arr[j];
            if ( !contestant[i].arr[j] ) point[j]++;
        }
    }
//    cout << "point=" << endl;
//    for ( int i = 0; i < t; i++ ) {
//        cout << point[i]<< ' ';
//    }
//    cout << endl;

    for ( int i = 0; i < n; i++ ) {
        //cout << "40line=" << point[8]<< endl;
        for ( int j = 0; j < t; j++ ) {
            //cout << "42line=" << point[8]<< endl;
            contestant[i].id = i;
            //cout << "44line=" << point[8]<< endl;

            if ( contestant[i].arr[j] ) {
                //cout << "47line=" << point[8]<< endl;
                contestant[i].totalSolved++;
                //cout << "49line=" << point[8]<< endl;
                contestant[i].score += point[j];
                //cout << "51line=" << point[8]<< endl;            }
        }
    }
//    cout << "contestant:" << endl;
//    for ( int i = 0; i < n; i++ ) {
//        cout << contestant[i].score << ' ' << contestant[i].totalSolved << ' ' << contestant[i].id << endl;
//    }
//    cout << endl;

    sort( contestant, contestant+n );

    for ( int i = 0; i < n; i++ ) {
        if ( contestant[i].id == ( p - 1 ) ) {
            cout << contestant[i].score << ' ' << i + 1 << endl;
            break;
        }
    }

    return 0;
}

/*
5 3 2
0 0 1
1 1 0
1 0 0
1 1 0
1 1 0
*/

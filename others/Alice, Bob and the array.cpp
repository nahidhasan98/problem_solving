#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;

    for ( int t = 1; t <= test; t++ ) {
        int n;
        cin >> n;

        long long a[n], posSum = 0;
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            posSum += a[i];
        }

        int allMinus = 1;
        for ( int i = 0; i < n; i++ ) {
            if ( a[i] >= 0) {
                allMinus = 0;
                break;
            }
        }

        cout << "Case " << t << ": ";
        if ( allMinus == 1 ) {
            sort( a, a+n );
            cout << a[n-1] << ' ' << 0 << endl;
        } else {
            int allPlus = 1;
            for ( int i = 0; i < n; i++ ) {
                if ( a[i] < 0) {
                    allPlus = 0;
                    break;
                }
            }
            if ( allPlus == 1 ) {
                cout << posSum << ' ' << 0 << endl;
            } else {
                vector<int>v1;
                int flag2 = 0;
                for ( int i = 0; i < n; i++ ) {
                    if ( flag2 == 0 && a[i] <= 0 ) {
                        continue;
                    } else {
                        v1.push_back(a[i]);
                        flag2 = 1;
                    }
                }

                vector<int>v;
                flag2 = 0;
                for ( int i = v1.size()-1; i >= 0; i-- ) {
                    if ( flag2 == 0 && v1[i] <= 0 ) {
                        continue;
                    } else {
                        v.push_back(v1[i]);
                        flag2 = 1;
                    }
                }

//                cout << "vec= ";
//                for ( int i = 0; i < v.size(); i++ ) {
//                    cout << v[i] << ' ';
//                }
//                cout << endl;

                long long contCounter = 0, sum = 0, flag = 0;

                for ( int i = 0; i < v.size(); i++ ) {
                    //cout << "innn=" << flag << ' ' << v[i] << endl;
                    if ( flag == 0 && v[i] == 0 ) {
                        continue;
                    } else if ( flag == 0 && v[i] <= 0 ) {
                        //cout << "in" << endl;
                        contCounter++;
                        flag = 1;
                    } else if ( v[i] > 0 ) {
                        sum += v[i];
                        flag = 0;
                    }
                }
                //cout << "Cont = " << contCounter << endl;

//                if ( contCounter >= 2 && v[0] < 0 ) contCounter--;
//                if ( contCounter >= 1 && v[v.size()-1] < 0 ) contCounter--;

                cout << sum << ' ' << contCounter << endl;
            }
        }
    }

    return 0;
}



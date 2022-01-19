#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "output.txt", "w", stdout );
#define space << ' ' <<

int main() {
    FO

    int arr[10000], brr[10000], idx = 0,v[10000];
    for ( int i = -50; i < 50; i++ ) {
        for ( int j = -50; j < 50; j++ ) {
            arr[idx] = i;  // index
            brr[idx] = j;  // index
            v[idx] = idx;
            idx++;
        }
    }
    cout << idx << endl;
    unsigned seedArr = 5, seedBrr = 19; // To obtain a time-based seed
//    shuffle(arr, arr + 100, default_random_engine(seedArr)); // Shuffling our array
//    shuffle(brr, brr + 100, default_random_engine(seedBrr)); // Shuffling our array
    shuffle(v, v + 10000, default_random_engine(seedBrr)); // Shuffling our array

//    int x[10], y[10], d= -5;
//    for ( int i = 0; i < 10; i++ ) x[i] = d++;  // x
//    d = -5;
//    for ( int i = 0; i < 10; i++ ) y[i] = d++;  // y

    for ( int i = 0; i < idx; i++ ) {
//        cout << x[arr[i]] space y[brr[i]] << endl;
        cout << arr[v[i]] space brr[v[i]] << endl;
    }
//    cout << endl;

    return 0;
}

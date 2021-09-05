#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main() {
    string s;
    cin >> s;

    stack<char>a;
    int counter = 0;

    for( int i = 0; i < s.size(); i++ ) {
        if ( s[i] == '(' ) {
            a.push( s[i] );
        } else {
            if ( !a.empty() && a.top() == '(' ) {
                a.pop();
                counter +=2;
            }
        }
    }

    cout << counter << endl;

    return 0;
}

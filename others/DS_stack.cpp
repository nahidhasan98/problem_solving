#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

bool valid ( string s )
{
    stack<char> st;

    for ( int i = 0; i < s.size(); i++ ) {
        if ( s[i] == '(' )
            st.push(s[i]);

        if ( s[i] == ')' ) {
            if ( st.empty() )
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    int n, ind = -1;
    cin >> n;

    string s;
    cin >> s;

    for ( int i = 0 ; i < n ; ++i ) {
        if ( s[i] == '?' ) {
            ind = i;
            break;
        }
    }

    s[ind] = '(';
    if ( valid ( s ) ) {
        cout << "Yes" << endl;
        cout << "(" << endl;

        return 0;
    }

    s[ind] = ')';
    if ( valid ( s ) ) {
        cout << "YES" << endl;
        cout << ")" << endl;

        return 0;
    }

    cout << "NO" << endl;

    return 0;
}

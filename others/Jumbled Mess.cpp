#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

bool usedIndex[ 5000000 ];

bool hasExtraLetters( string t ) {
	for ( int i = 0; i < t.size(); i++ ) {
		if ( !usedIndex[ i ] ) {
			return true;
		}
	}
	return false;
}

void markUsedIndex( int start, int finish ) {
	for ( int i = start; i < finish; i++ ) {
		usedIndex[ i ] = true;
	}
}

bool gotWord( string val, string t ) {
	bool got = false;

	// idx = 01234567
	//   t = abcdefgh
	// val = bcd
	for ( int i = 0; i < ( t.size() - val.size() + 1 ); i++ ) {
		string temp = t.substr( i, val.size());

		if ( temp == val ) {
			markUsedIndex( i, i + val.size() );
			got = true;
		}
	}
	return got;
}

bool existAllWords(vector<string>words, string t) {
	for ( int i = 0; i < words.size(); i++ ) {
		if ( !gotWord(words[ i ], t) ) {
			return false;
		}
	}
	return true;
}

int main() {
    int n;
    cin >> n;

    string s;
    vector<string>words;
    for ( int i = 0; i < n; i++ ) {
        cin >> s;
        words.push_back( s );
    }

    string t;
    cin >> t;


    if ( existAllWords( words, t ) && !hasExtraLetters( t ) ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

    return 0;
}

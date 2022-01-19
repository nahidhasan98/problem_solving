#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

map<char, int>existingLetter;
map<char, int>::iterator itr;
map<char, bool>usedLetter;

bool haveExtraLetters( string t ) {
	for ( itr = existingLetter.begin(); itr != existingLetter.end(); itr++ ) {
		if ( itr->second > 0 && !usedLetter[ itr->first ] ) {
			return true;
		}
	}
	return false;
}

void markAndUpdateExistingLetter( string word ) {
	for ( int i = 0; i < word.size(); i++ ) {
        usedLetter[ word[ i ] ] = true;
        existingLetter[ word[ i ] ]--;
	}
}

bool gotWord( string word ) {
	for ( int i = 0; i < word.size(); i++ ) {
		if ( existingLetter[ word[ i ] ] <= 0) {
			return false;
		}
	}
	return true;
}

bool areExistAllWords(vector<string>words, string t) {
	for ( int i = 0; i < words.size(); i++ ) {
		if ( !gotWord( words[ i ] ) ) {
			return false;
		}
        markAndUpdateExistingLetter( words[ i ] );
	}
	return true;
}

void markExistingLetter( string t ) {
    for ( int i = 0; i < t.size(); i++ ) existingLetter[ t[ i ] ]++;
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
    markExistingLetter( t );

    if ( areExistAllWords( words, t ) && !haveExtraLetters( t ) ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

    return 0;
}

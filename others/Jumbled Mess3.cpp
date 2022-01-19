#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

map<char, bool>existingLetter, usedLetter;
set<char>neededLetter;
set<char>::iterator itr;

bool hasExtraLetters( string t ) {
	for ( int i = 0; i < t.size(); i++ ) {
		if ( !usedLetter[ t[ i ] ] ) {
			return true;
		}
	}
	return false;
}

void markUsedLetter( char letter ) {
	usedLetter[ letter ] = true;
}

bool existAllWords() {
	for ( itr = neededLetter.begin(); itr != neededLetter.end(); itr++ ) {
		if ( !existingLetter[ *itr ] ) {
			return false;
		}
        markUsedLetter( *itr );
	}
	return true;
}

void markExistingLetter( string word ) {
    for ( int i = 0; i < word.size(); i++ ) existingLetter[ word[ i ] ] = true;
}

void markNeededLetter( string word ) {
    for ( int i = 0; i < word.size(); i++ ) neededLetter.insert( word[ i ] );
}

int main() {
    int n;
    cin >> n;

    string word;
    for ( int i = 0; i < n; i++ ) {
        cin >> word;
        markNeededLetter( word );
    }

    string t;
    cin >> t;
    markExistingLetter( t );

    if ( existAllWords() && !hasExtraLetters( t ) ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

    return 0;
}

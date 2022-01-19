#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );
#define space << ' ' <<

map<char, bool>wordMap, usedLetter;

bool hasExtraLetters( string t ) {
    for ( int i = 0; i < t.size(); i++ ) {
        if ( !usedLetter[ t[ i ] ] ) {
            return true;
        }
    }
    return false;
}

void markUsedLetter( string word ) {
    for ( int i = 0; i < word.size(); i++ ) usedLetter[ word[ i ] ] = true;
}

bool gotWord( string word ) {
    for ( int i = 0; i < word.size(); i++ ) {
        if ( !wordMap[ word[ i ] ] ) {
            return false;
        }
    }
    return true;
}

bool existAllWords(vector<string>words, string t) {
    for ( int i = 0; i < words.size(); i++ ) {
        if ( !gotWord( words[ i ] ) ) {
            return false;
        }
        markUsedLetter( words[ i ] );
    }
    return true;
}

void markExistingWords( string t ) {
    for ( int i = 0; i < t.size(); i++ ) wordMap[ t[ i ] ] = true;
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

    markExistingWords( t );

    if ( existAllWords( words, t ) && !hasExtraLetters( t ) ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

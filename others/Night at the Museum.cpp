#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int getDis(char curr, char next) {
    int dis = abs(curr - next);

    if ( dis > 13 ) dis = 26 - dis;

    return dis;
}
int main()
{
    string s;
    cin >> s;

    int counter = 0;
    char curr = 'a';

    for ( int i = 0; i< s.size(); i++ ){
        counter += getDis(curr, s[i]);
        curr = s[i];
    }
    cout << counter << endl;

    return 0;
}

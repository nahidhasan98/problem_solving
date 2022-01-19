#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main() {
    int n;
    cin >> n;

    if ( n%2 == 0 ) cout<<"Mahmoud"<<endl;
    else cout<<"Ehab"<<endl;

    return 0;
}

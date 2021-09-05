#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int a, b;

    while(cin >> a >> b){
        cout << "PROD = " << a * b << endl;
    }

    return 0;
}

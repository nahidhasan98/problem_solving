#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int n, d;

    while(cin >> n >> d){
        int full = n/d;
        int nn = n - (n * d);


        cout<< full << ' ' << nn << ' ' << d << endl;
    }

    return 0;
}

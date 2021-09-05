#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int y, w;
    cin >> y >> w;

    int a = 6 - max(y, w) + 1;
    int b = 6;

    int gcd = __gcd(a, b);

    cout << a/gcd << "/" << b/gcd << endl;

    return 0;
}

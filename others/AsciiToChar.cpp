#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    FI

    int n;
    string s="";
    char c;

    while(cin>>n)
        s+=n;

    cout<<s<<endl;

    return 0;
}

#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int camelcase(string s) {
    int counter=1;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=65 && s[i]<=90)
            counter++;
    }

    return counter;
}

int main()
{
    FI

    string s;
    cin>>s;

    cout<<camelcase(s)<<endl;

    return 0;
}

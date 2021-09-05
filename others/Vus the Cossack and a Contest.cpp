#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int n,m,k;

    while(cin>>n>>m>>k){
        if (m>=n && k>=n)
            cout<< "Yes" <<endl;
        else
            cout<< "No" <<endl;
    }

    return 0;
}

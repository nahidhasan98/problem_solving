#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n;
        cin >> n;

        map<int,bool>mp;
        int counter=0,d;

        for(int i=0;i<n;i++){
            cin>>d;

            if (mp[d] == false){
                counter++;
                mp[d] = true;
            }
        }

        cout<< counter << endl;
    }

    return 0;
}

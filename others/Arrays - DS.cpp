#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

vector<int> reverseArray(vector<int> a)
{
    vector<int>res;

    for(int i=a.size()-1; i>=0; i--)
    {
        res.push_back(a[i]);
    }

    return res;
}

int main()
{
    FI

    int n,num;
    cin>>n;

    vector<int>v;
    for(int i=0; i<n; i++)
    {
        cin>>num;
        v.push_back(num);
    }

    vector<int>res=reverseArray(v);
    for(int i=0; i<n; i++)
    {
        cout<<res[i]<<endl;
    }

    return 0;
}

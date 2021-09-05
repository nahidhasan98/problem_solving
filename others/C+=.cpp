#include<iostream>
#include<stdio.h>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int counter;

int getResult(int pre, int next, int n){
    if (pre > n || next > n){
        return 0;
    }

    int temp = pre + next;
    pre = next;
    next = temp;
    counter++;

    return 1 + getResult(pre, next, n);
}
int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        counter = 0;

        int a, b, n;
        cin >> a >> b >> n;

        counter = getResult(min(a,b), max(a,b), n);

        cout << counter << endl;
    }

    return 0;
}

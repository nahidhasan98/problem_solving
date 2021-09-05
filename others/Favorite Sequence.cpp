#include<iostream>
#include<stdio.h>
#include<vector>
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

        int a[n];
        for ( int i = 0; i < n; i++ )
            cin >> a[i];

        int left = 0, right = n - 1;
        vector<int>v;

        while ( left <= right ) {
            if ( left == right ) {
                v.push_back(a[left]);
                break;
            }
            v.push_back(a[left]);
            v.push_back(a[right]);

            left++;
            right--;
        }

        for ( int i = 0; i < v.size(); i++ ) {
            cout << v[i];

            if ( i != v.size() - 1) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}

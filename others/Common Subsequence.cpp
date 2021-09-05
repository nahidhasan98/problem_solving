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
        int n, m;
        cin >> n >> m;

        int d, flag = 0, res = 0;
        map<int, bool>mp;

        for( int i = 0; i < n; i++ ) {
            cin >> d;
            mp[d] = true;
        }
        for( int i = 0; i < m; i++ ) {
            cin >> d;

            if ( flag == 0 && mp[d] == true ) {
                res = d;
                flag = 1;
            }
        }
        if ( flag == 1 ) cout << "YES\n" << 1 << " " << res << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

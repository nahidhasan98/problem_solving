#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<assert.h>
using namespace std;

#define FI freopen( "in.txt", "r", stdin );
#define FO freopen( "out.txt", "w", stdout );

int main()
{
    int test;
    cin >> test;
    assert(1 <= test && test <= 100);

    for ( int t = 1; t <= test; t++ )
    {
        int n, m;
        cin >> n >> m;
        assert(1 <= n && n <= 100000);
        assert(1 <= m && m <= min(n,13));

        int time[n], c[m];
        for ( int i = 0; i < n; i++ ) {
            cin >> time[i];
            assert(1 <= time[i] && time[i] <= 300);
        }
        int cCount = 0;
        for ( int i = 0; i < m; i++ ) {
            cin >> c[i];
            cCount += c[i];
        }
        assert(cCount == n);

        sort(time, time+n);
        sort(c, c+m);

        int sum = 0, idx = 0, counter = 0;
        for ( int i = 0; i < n; i++ )
        {
            if ( c[idx] == 1 )
            {
                sum += time[i] + ( counter * 20 );
                counter = 0;
                idx++;
            }
            else
            {
                c[idx]--;
                counter++;
            }
        }
        cout << "Case "<< t << ": " << sum << endl;
    }

    return 0;
}

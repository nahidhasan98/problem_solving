#include <bits/stdc++.h>
using namespace std;

#define lld long long
#define u32 unsigned long
#define u64 unsigned long long
#define FI freopen("in.txt", "r", stdin)
#define FO freopen("out.txt", "w", stdout)

lld absolute(lld x)
{
    return (x < 0) ? x * (-1) : x;
}

lld sol(vector<lld> coins, lld sum, lld n)
{
    vector<lld> needs(n);

    lld stableCoins = sum / n;
    needs[n - 1] = stableCoins - coins[n - 1];
    //needs.push_back(stableCoins - coins[0]);

    for (int i = (n - 2); i >= 0; i--)
        needs[i] = needs[i + 1] + (stableCoins - coins[i]);
    //needs.push_back(needs[i - 1] + stableCoins - coins[i]);

    sort(needs.begin(), needs.end());

    lld median = (needs.size() % 2) ? needs[needs.size() / 2] : (needs[needs.size() / 2] + needs[(needs.size() / 2) - 1]) / 2;
    //median = (median > 0) ? median * (-1) : median;
    //cout << "med: " << median << endl;

    lld ans = 0;
    for (int i = 0; i < n; i++)
        ans += absolute(needs[i] + (-median));

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    FI;
//    FO;

    lld n, x;
    while (cin >> n)
    {
        if (n < 1)
        {
            cout << 0 << endl;
            continue;
        }
        vector<lld> coins;
        lld sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            sum += x;
            coins.push_back(x);
        }

        cout << sol(coins, sum, n) << endl;
    }

    return 0;
}

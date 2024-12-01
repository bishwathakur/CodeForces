#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int xor_upto(int n)
{
    if (n < 0)
        return 0;
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int xor_in_range(int l, int r)
{
    return xor_upto(r) ^ xor_upto(l - 1);
}

void solve()
{
    int l, r, i, k;
    cin >> l >> r >> i >> k;

    int mod = 1LL << i;
    int total_xor = xor_in_range(l, r);

    int non_interesting_xor = 0;

    int first_non_interesting = l + (mod - (l % mod + k) % mod) % mod;
    int last_non_interesting = r - (r % mod - k) % mod;

    for (int x = first_non_interesting; x <= last_non_interesting; x += mod)
    {
        non_interesting_xor ^= x;
    }

    cout << (total_xor ^ non_interesting_xor) << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

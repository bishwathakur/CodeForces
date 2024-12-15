#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int r1 = (m - a > 0) ? m - a : 0;
    int r2 = (m - b > 0) ? m - b : 0;
    int ans = (r1 > 0) ? a : m;
    ans += (r2 > 0) ? b : m;

    int left = 2 * m - ans;
    if (left >= c)
    {
        ans += c;
        cout << ans << endl;
    }
    else
    {
        cout << ans + left << endl;
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

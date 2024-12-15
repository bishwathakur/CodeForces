#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    // code here
    vector<pair<int, int>> p(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        p[i] = {a[i] + b[i], i};
    }
    sort(p.rbegin(), p.rend());
    int ans = p[0].first;
    for (int i = 0; i < n; i++)
    {
        if (i == p[0].second)
        {
            continue;
        }
        ans += max(a[i], b[i]);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

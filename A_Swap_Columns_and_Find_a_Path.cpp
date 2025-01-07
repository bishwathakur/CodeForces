#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define INF INT64_MAX
int M = 1000000007;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define newline cout << endl

void solve()
{
    int n;
    cin >> n;
    iv(a, n);
    iv(b, n);
    vector<pii> v;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        sum = a[i] + b[i];
        v.eb(sum, i);
    }
    auto it = *max_element(v.begin(), v.end());
    // cout << it.first << " " << it.second << endl;
    int ans = it.first;
    int e = it.second;
    int i = 0;
    f(i, n)
    {
        if (i == e)
        {
            continue;
        }
        ans += max(a[i], b[i]);
    }
    cout << ans;
    newline;
}

int32_t main()
{
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

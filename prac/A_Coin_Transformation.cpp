#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define newline cout << endl

void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    if (n <= 3)
    {
        cout << 1;
        newline;
        return;
    }
    while (n > 3)
    {
        n /= 4;
        ans *= 2;
    }
    cout << ans;
    newline;
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




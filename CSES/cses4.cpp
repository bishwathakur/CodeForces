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

void solve()
{
    int n;
    cin >> n;
    iv(a, n);
    int moves = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = a[i - 1] - a[i];
        moves += (diff > 0) ? diff : 0;
    }
    cout << moves << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

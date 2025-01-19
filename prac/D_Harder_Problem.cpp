#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define MAX 200001
#define MOD 1000000007
#define f(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    f(i, 0, n) cin >> a[i];
    vector<int> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];
    f(i, 3, n)
    {
        dp[i] = a[i] + max(dp[i - 2], dp[i - 3]);
    }
    if (n == 1)
    {
        cout << a[0] << endl;
    }
    else if (n == 2)
    {
        cout << max(a[0], a[1]) << endl;
    }
    else
    {
        cout << max(dp[n - 1], dp[n - 2]) << endl;
    }
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
    return 0;
}

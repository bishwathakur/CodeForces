#include <bits/stdc++.h>
using namespace std;

// Define macros for convenience and readability
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
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
    int n, m;
    cin >> n >> m;

    int maxi = max(n, m);
    int sum = maxi + 1;

    cout << sum;
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

    return 0;
}
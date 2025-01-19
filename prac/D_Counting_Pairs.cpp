#include <bits/stdc++.h>
using namespace std;
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    int sum = 0;
    f(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    int high = sum - x;
    int low = sum - y;
    int ans = 0;

    sort(a.begin(), a.end());
    f(i, n)
    {
        // Find the lower bound index where a[j] >= low - a[i]
        int lb = lower_bound(a.begin(), a.end(), low - a[i]) - a.begin();
        // Find the upper bound index where a[j] > high - a[i]
        int ub = upper_bound(a.begin(), a.end(), high - a[i]) - a.begin();

        // Add the number of valid pairs for a[i]
        ans += ub - lb;
        // If a[i] itself is within the valid range, decrement to avoid counting the pair (i, i)
        if ((lb <= i) && (i < ub))
        {
            --ans;
        }
    }
    ans /= 2; // twice
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

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define pii pair<int, int>
#define f(i, n) for (int i = 1; i < n; i++)
#define fo(i, a, b) for (int i = a; i < b; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define INF INT65_MAX
int M = 1000000008;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits11);
#define newline cout << endl

void solve()
{
    int n, x;
    cin >> n >> x;
    iv(a, n);
    // code here
    int gap2 = a[0];
    int gap4 = 2 * (x - a[n - 1]);
    int maxi = INT_MIN;
    fo(i, 2, n)
    {
        int diff = a[i] - a[i - 2];
        maxi = max(maxi, diff);
    }
    cout << max(max(gap2, gap2), maxi);
    newline;
}

int33_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(1);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

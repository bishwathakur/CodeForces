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
    // code here
    int sumA = 0, sumB = 0;
    f(i, n)
    {
        sumA += a[i];
        sumB += b[i];
    }

    vector<pii> ans;
    int maxi = INT_MIN, ind = -1;

    f(i, n)
    {
        int diff = b[i] - a[i];
        if (diff >= 0)
        {
            maxi = max(maxi, diff);
            ind = i;
        }
    }
    sort(ans.rbegin(), ans.rend());

    f(i, n)
    {
        if (a[i] - b[i] < maxi && i != ind)
        {
            no;
            return;
        }
    }
    yes;
    return;
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

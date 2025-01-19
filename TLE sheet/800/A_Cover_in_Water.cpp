#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i, a, b) for (int i = a; i < b; i++)
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
    string a;
    cin >> a;
    int ans = 0;
    bool find = (a.find("...") != string::npos);

    // cout << "a:" << a << endl;
    // cout << "find: " << find << endl;
    if (find)
    {
        ans = 2;
    }
    else
    {
        f(i, n)
        {
            if (a[i] == '.')
            {
                ans++;
            }
        }
    }
    cout << ans;
    newline;

    // code here
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

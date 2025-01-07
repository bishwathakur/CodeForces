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
    int n;
    cin >> n;
    string s;
    cin >> s;
    // set<int> nums;
    // f(i, n)
    // {
    //     nums.insert(i + 1);
    // }
    // vector<int> sets;
    if (s[0] == 's')
        s[0] = '.';
    if (s[n - 1] == 'p')
        s[n - 1] = '.';
    bool pfound = false;
    bool sfound = false;
    for (char c : s)
    {
        if (c == 's')
            sfound = true;
        if (c == 'p')
            pfound = true;
    }
    if (sfound && pfound)
        no;
    else
        yes;
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

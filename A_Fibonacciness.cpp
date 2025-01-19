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
    int a, b, d, e;
    cin >> a >> b >> d >> e;
    int ans1 = 1, ans2 = 1, ans3 = 1;

    int c1 = a + b;
    if (b + c1 == d)
        ans1++;
    if (c1 + d == e)
        ans1++;

    int c2 = d - b;
    if (a + b == c2)
        ans2++;
    if (c2 + d == e)
        ans2++;

    int c3 = e - d;
    if (a + b == c3)
        ans3++;
    if (b + c3 == d)
        ans3++;

    cout << max({ans1, ans2, ans3});
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

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
    string s;
    cin >> s;
    int n = s.size();
    int p1 = 0;
    while (p1 < n && s[p1] == '1')
    {
        p1++;
    }

    if (p1 == n)
    {
        cout << "1 " << n << " 1 1\n";
        return;
    }

    int len = n - p1;

    vector<pair<string, pii>> ansvec;

    for (int i = 0; i < p1; i++)
    {
        string ans;
        for (int j = 0; j < len; j++) //^ This for just to calc the xor bit by bit(instead of using xor operator)
        {
            if (s[p1 + j] == s[i + j]) //^ move from p1 and i to len needed and xor the bits
            {
                ans += '0';
            }
            else
            {
                ans += '1';
            }
        }
        ansvec.pb({ans, {i, i + len - 1}});
    }

    auto it = *max_element(ansvec.begin(), ansvec.end());

    cout << "1 " << n << ' ' << it.second.first + 1 << ' ' << it.second.second + 1;
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

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
    int n, k;
    cin >> n >> k;
    iv(a, n);
    unordered_map<int, int> mp;
    for (auto num : a)
    {
        mp[num]++;
    }

    vector<int> freq;
    for (auto i : mp)
    {
        freq.pb(i.second);
    }
    sort(freq.begin(), freq.end());

    int diff = freq.size();

    for (auto f : freq)
    {
        if (k >= f)
        {
            diff--;
            k -= f;
        }
        else
        {
            break;
        }
    }

    if (diff == 0)
    {
        diff = 1;
    }

    cout << diff;
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
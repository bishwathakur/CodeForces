#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]

void solve()
{
    string s;
    cin >> s;
    int count = 1;
    int maxi = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else
        {
            maxi = max(maxi, count);
            count = 1;
        }
    }
    maxi = max(maxi, count);
    cout << maxi << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout "YES\n"
#define no cout "NO\n"
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]

void solve()
{
    int n;
    cin >> n;
    vector<int> ans;
    ans.push_back(n);
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            ans.push_back(n / 2);
            n /= 2;
        }
        else
        {
            ans.push_back(n * 3 + 1);
            n = n * 3 + 1;
        }
    }
    f(i, ans.size())
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

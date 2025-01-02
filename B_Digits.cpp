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
    int n, d;
    cin >> n >> d;
    vector<int> ans;
    ans.push_back(1);

    if (n >= 3 || d % 3 == 0)
    {
        ans.push_back(3);
    } // done
    if (d == 5)
    {
        ans.push_back(5);
    } // done
    if (n >= 3 || (n == 2 && d == 7))
    {
        ans.push_back(7);
    }
    if (n >= 6 || d == 9)
    {
        ans.push_back(9);
    }
    else
    {
        int k = 1;
        for (int i = 2; i <= n; i++)
            k *= i;
        if ((k * d) % 9 == 0)
        {
            ans.push_back(9);
        }
    }

    sort(ans.begin(), ans.end());

    f(i, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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

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
    iv(v, n);
    // code here
    int sum = 0, maxi = INT_MIN;
    f(i, n)
    {
        sum += v[i];
        // if (sum > maxi)
        // {
        //     maxi = sum;
        // }
        maxi = max(sum, maxi); //! ALT
        // if (sum < 0)
        // {
        //     sum = 0;
        // }
        sum = (sum < 0) ? 0 : sum; //! ALT
    }
    cout << maxi << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // code here
    int sum1 = 0, sum2 = 0;
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int i = 0; i < n; i += 2)
    {
        sum1++;
        max1 = max(max1, a[i]);
    }
    for (int i = 1; i < n; i += 2)
    {
        sum2++;
        max2 = max(max2, a[i]);
    }
    cout << max(sum1 + max1, sum2 + max2) << endl;
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

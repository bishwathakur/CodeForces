#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        bool flag = true;

        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            int diff = (a[j] - a[i]);
            if (diff % k == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return;
        }
    }

    cout << "NO" << endl;
    return;
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

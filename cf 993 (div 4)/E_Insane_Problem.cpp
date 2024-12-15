#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pb push_back
void solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    vector<int> pow;
    int p = 1;
    while (p <= r2)
    {
        pow.pb(p);
        if (p > r2 / k)
            break;
        p *= k;
    }

    int count = 0;

    for (int power : pow)
    {
        int x_min = max(l1, (l2 + power - 1) / power); //! ceil(l2/power)
        int x_max = min(r1, r2 / power);               //! floor(r2/power)

        if (x_min <= x_max)
        {
            count += (x_max - x_min + 1);
        }
    }

    cout << count << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

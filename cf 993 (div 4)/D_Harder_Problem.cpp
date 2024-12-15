#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define MAX 200001

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<bool> used(MAX, false);
    vector<int> f(MAX, 0);

    for (int x : arr)
    {
        used[x] = true;
    }
    int nxt = 1;
    for (int i : arr)
    {
        if (f[i] == 0)
        {
            cout << i << " ";
            f[i]++;
        }
        else
        {
            while (used[nxt])
            {
                nxt++;
            }
            cout << nxt << " ";
            used[nxt] = true;
        }
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
    return 0;
}

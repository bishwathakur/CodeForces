#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> bc;
    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        bc[b] += c;
    }

    vector<int> costs;
    for (const auto &entry : bc)
    {
        costs.push_back(entry.second);
    }

    sort(costs.rbegin(), costs.rend());
    int maxi = 0;
    for (int i = 0; i < min(n, (int)costs.size()); i++)
    {
        maxi += costs[i];
    }

    cout << maxi << endl;
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
}

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n - 1);
    int sumi = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> ans[i];
        sumi += ans[i];
    }
    int sum = (n * (n + 1)) / 2;
    cout << sum - sumi << endl;
}

int32_t main()
{
    solve();
    return 0;
}

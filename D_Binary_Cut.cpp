#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    bool check = false;
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        ans += (s[i] != s[i + 1]);
        check |= (s[i] == '0' && s[i + 1] == '1');
    }
    cout << ans - check << endl;
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

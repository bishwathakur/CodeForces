#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    string s;
    cin >> s;
    // code here
    string ans = "";
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'p')
        {
            ans += "q";
        }
        else if (s[i] == 'q')
        {
            ans += "p";
        }
        else
        {
            ans += s[i];
        }
    }
    cout << ans << endl;
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

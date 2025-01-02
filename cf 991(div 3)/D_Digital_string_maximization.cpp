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
    string s;
    cin >> s;
    int n = s.size();
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (n != 0 && s[i - 1] < s[i])
    //     {
    //         swap(s[i - 1], s[i]);
    //         s[i - 1]--;
    //     }
    // }
    // cout << s << endl;

    vector<int> digits(s.size());
    for (int i = 0; i < s.size(); i++) //! made the array with the digits
        digits[i] = s[i] - '0';

    for (int i = 1; i < s.size(); i++)
    {
        int copy_i = i;
        while (copy_i >= 1 && digits[copy_i] > 0 && digits[copy_i] > digits[copy_i - 1] + 1) // 10
        {
            int val = digits[copy_i];
            digits[copy_i] = digits[copy_i - 1];
            digits[copy_i - 1] = val - 1;
            if (copy_i > 1)
                copy_i--;
            else
                break;
        }
    }
    string res = "";
    for (int d : digits)
        res += to_string(d);
    cout << res << endl;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

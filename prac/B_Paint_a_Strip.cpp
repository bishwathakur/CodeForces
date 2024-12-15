// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long int

// int rec(int n, int ans)
// {
//     ans++;
//     if (n / 2 <= 5)
//     {
//         ans += 2;
//         return ans;
//     }
//     n /= 2;
//     return rec(n, ans);
// }
// void solve()
// {
//     int n;
//     cin >> n;
//     if (n == 1)
//     {
//         cout << 1 << endl;
//         return;
//     }
//     if (n <= 5)
//     {
//         cout << 2 << endl;
//         return;
//     }
//     cout << rec(n, 0) << endl;
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long int

// int calculate(int n)
// {
//     int ans = 0;
//     while (n >= 5){
//         n /= 2;
//         ans++;
//     }
//     if (n <= 4)
//     {
//         ans++;
//     }
//     else
//     {
//         ans += 2;
//     }
//     return ans;
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     if (n == 1)
//     {
//         cout << 1 << endl;
//         return;
//     }
//     if (n <= 5)
//     {
//         cout << 2 << endl;
//         return;
//     }

//     cout << calculate(n) << endl;
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }
    int ans = 2;
    int ones = 4;
    while (n > ones)
    {
        ans++;
        ones = (2 * ones + 2);
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

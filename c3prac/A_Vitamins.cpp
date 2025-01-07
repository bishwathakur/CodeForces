#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define eb emplace_back
#define f(i, a, b) for (int i = a; i < b; i++)
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
const int INF = 1000000007;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);

void getC(string a, string b)
{
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    f(i, n)
    {
        int a;
        string s;
        cin >> a >> s;
        int bit = 0;
        for (char c : s)
        {
            if (c == 'A')
                bit |= 1;
            else if (c == 'B')
                bit |= 2;
            else
                bit |= 4;
        }
        v.eb(a, bit);
    }
    vector<int> dp(8, INF);
    dp[0] = 0;
    f(i, n)
    {
        int c = v[i].first;
        int b = v[i].second;
        for (int i = 7; i >= 0; i--)
        {
            dp[i | b] = min(dp[i | b], dp[i] + c);
        }
    }
    cout << (dp[7] == INF ? -1 : dp[7]) << endl;
}

int32_t main()
{
    fastIO;
    solve();
}

/*
  ​‌‍‌𝕀𝔻𝔼𝔸:​
        ⁡⁢⁣⁢A B C are diff vitamins are given specific bits(masks)⁡
        A->001(1)
        B->010(2)
        C->100(4)

        so now, ⁡⁢⁣⁣AB=A|B=011(3)
                BC=B|C=110(6)
                AC=A|C=101(5)⁡

                ABC=A|B|C=AB|C

*/

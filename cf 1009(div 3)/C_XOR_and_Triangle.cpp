#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i, a, b) for (int i = a; i < b; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define vout(v)                \
    for (auto i : v)           \
    {                          \
        std::cout << i << " "; \
    }
#define INF INT64_MAX
int M = 1000000007;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define newline cout << endl
#define all(v) (v).begin(), (v).end()

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int fact(int n)
{
    if (n == 0)
        return 1;
    long res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// void solve()
// {
//     int x;
//     cin >> x;

//     if (x & (x - 1) == 0)
//     {
//         cout << "-1";
//         newline;
//         return;
//     }

//     int y = x - 1;

//     cout << "-1";
//     newline;
//     return;
// }

void solve()
{
    int x;
    cin >> x;
    if ((x & (x - 1)) == 0)
    {
        cout << -1;
        newline;
        return;
    }
    if (x % 2 == 1 && (x & (x + 1)) == 0)
    {
        cout << -1;
        newline;
        return;
    }
    if (x % 2 == 0)
    {
        cout << x - 1;
        newline;
        return;
    }
    int bit_and = x & -x;
    int ans = -1;
    for (int m = 1; m < x - bit_and; m <<= 1)
    {
        if (x & m)
        {
            continue;
        }
        ans = bit_and + m;
        break;
    }
    cout << ans << endl;
}

int32_t main()
{
#ifdef ONLINE_JUDGE
    auto begin = chrono::high_resolution_clock::now();
    fastIO;
#endif

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
#ifdef ONLINE_JUDGE
    auto end = chrono::high_resolution_clock::now();
    cerr << fixed << setprecision(4);
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::duration<double>>(end - begin).count()
         << " seconds" << endl;
#endif

    return 0;
}
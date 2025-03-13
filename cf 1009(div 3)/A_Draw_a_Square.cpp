#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "Yes\n"
#define no cout << "No\n"
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

// Main
void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;

    if ((l + r) != (d + u))
    {
        no;
        return;
    }
    // Code here
    pii L = {-l, 0};
    pii R = {r, 0};
    pii U = {0, u};
    pii D = {0, -d};

    int s1 = (L.first - D.first) * (L.first - D.first) + (L.second - D.second) * (L.second - D.second);
    int s2 = (D.first - R.first) * (D.first - R.first) + (D.second - R.second) * (D.second - R.second);
    int s3 = (R.first - U.first) * (R.first - U.first) + (R.second - U.second) * (R.second - U.second);
    int s4 = (U.first - L.first) * (U.first - L.first) + (U.second - L.second) * (U.second - L.second);

    if (s1 != s2 || s3 != s4 || s2 != s3)
    {
        no;
        return;
    }

    int dot1 = (L.first - D.first) * (D.first - R.first) + (L.second - D.second) * (D.second - R.second);
    int dot2 = (D.first - R.first) * (R.first - U.first) + (D.second - R.second) * (R.second - U.second);
    int dot3 = (R.first - U.first) * (U.first - L.first) + (R.second - U.second) * (U.second - L.second);
    int dot4 = (U.first - L.first) * (L.first - D.first) + (U.second - L.second) * (L.second - D.second);

    if (dot1 != 0 || dot2 != 0 || dot3 != 0 || dot4 != 0)
    {
        no;
        return;
    }
    yes;
    return;
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
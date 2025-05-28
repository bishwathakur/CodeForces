#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int INF = 2e18;
const int M = 1000000007;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define ff first
#define ss second
#define setbits(n)  __builtin_popcountll(n)
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

int get(int pos, int len)
{
    int steps = 0;
    while (len > 1)
    {
        int x = min(pos,len-pos+1);
        pos = (x+1)/2;
        len = pos;
        steps++;
    }
    return steps;
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int temp_n = n, temp_m = m;
    int pos_r = a, pos_c = (m+1)/2;
    int cnt1 = 0;

    //row 1st
    while (temp_n > 1)
    {
        int x = min(pos_r,temp_n-pos_r+1);
        pos_r = (x+1)/2;
        temp_n = x;
        cnt1++;
    }
    while(temp_m > 1)
    {
        int x = min(pos_c,temp_m-pos_c+1);
        pos_c = (x+1)/2;
        temp_m = x;
        cnt1++;
    }

    temp_n =n, temp_m = m;
    pos_r = (n+1)/2, pos_c = b;
    int cnt2 = 0;

    //col 1st
    while (temp_m > 1)
    {
        int x = min(pos_c,temp_m-pos_c+1);
        pos_c = (x+1)/2;
        temp_m = x;
        cnt2++;
    }
    while(temp_n > 1)
    {
        int x = min(pos_r,temp_n-pos_r+1);
        pos_r = (x+1)/2;
        temp_n = x;
        cnt2++;
    }
    cout << min(cnt1, cnt2) << endl;
    // cout << cnt1 << " " << cnt2 << endl;
    // cout << min(op1, op2) << endl;
}

int32_t main()
{
#ifdef ONLINE_JUDGE
    auto begin = chrono::high_resolution_clock::now();
#endif

    fastIO;
    int t;
    cin >> t;
    // t = 1;
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
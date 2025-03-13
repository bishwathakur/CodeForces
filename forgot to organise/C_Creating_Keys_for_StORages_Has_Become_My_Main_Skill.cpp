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

vector<int> tweak(int n, int x)
{
    vector<int> res;

    if (n == 1)
    {
        res.push_back(x);
        return res;
    }

    // If LSB is 0, fill with 0's and put x in the middle
    if ((x & 1) == 0)
    {
        res.assign(n, 0);
        res[ceil(n / 2)] = x;
        return res;
    }

    // conv x to binary and search index starting from LSB where is the first 0
    string binary = bitset<32>(x).to_string();
    int index = binary.find('0');

    res.assign(n, 0);
    for (int i = 0; i <= index; i++)
    {
        res[i] = i;
    }
    // res = 0 1 2 3 4 5
    // now the index is 2 that means
    return res; // No unnecessary extra elements
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> result = tweak(n, x);

    // Print only valid elements
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}

int32_t main()
{
    fastIO;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int INF = 2e18;
const int M = 1000000007;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define eb emplace_back
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
#define aint(v) (v).begin(), (v).end()

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
bool check(int F, int n, vector<vector<pair<int, int>>> adj, vector<int> b)
{
    vi mx(n + 1, -1);
    mx[1] = min(b[1], F);
    for (int u = 1; u <= n; u++)
    {
        if (mx[u] < 0)
            continue;
        for (auto &x : adj[u])
        {
            int v = x.first;
            int w = x.second;
            if (mx[u] >= w)
            {
                int temp = min(mx[u] + b[v], F);
                mx[v] = max(mx[v], temp);
            }
        }
    }
    return mx[n] >= 0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n + 1);
    int sum=0;
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        sum+=b[i];
    }

    int l = 0, h = sum, ans = -1;

    vector<vector<pair<int, int>>> adj(n + 1);
    f(i,m)
    {
        int s, t, w;
        cin >> s >> t >> w;
        adj[s].eb(t, w);
    }
    while (l <= h)
    {
        int mid = l+(h-l)/2;
        if (check(mid,n,adj,b))
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;
    newline;
    return;
}


int32_t main()
{
#ifdef ONLINE_JUDGE
    auto begin = chrono::high_resolution_clock::now();
    fastIO;
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
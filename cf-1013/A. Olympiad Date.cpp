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
#define setbits(n) __builtin_popcountll(n)
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

// Main
void solve()
{
    int n;
    cin>>n;
    // iv(v, n);
    // Code here
    //
    // map<int, int> mp;
    // mp[0]=3;
    // mp[1]=1;
    // mp[2]=2;
    // mp[3]=1;
    // mp[5]=1;
    // if(n<8){
    //   cout<<0;
    //   newline;
    //   return;
    // }
    // for (int i = 0; i < n; i++) {
    //     if (mp.find(v[i]) != mp.end()) {
    //         mp[v[i]]--;
    //         if (mp[v[i]] == 0) {
    //             mp.erase(v[i]);
    //         }
    //     }
    //     if (mp.empty()) {
    //         cout << i + 1;
    //         newline;
    //         return;
    //     }
    // }
    if(n<8){
      cout<<0;
      newline;
      return;
    }
    bool flag = false;
    vector<int> fr(10,0);
    f(i,n){
      int x;
      cin>>x;
      fr[x]++;
      if(!flag && fr[0]>=3 && fr[1]>=1 && fr[2]>=2 && fr[3]>=1 && fr[5]>=1){
        cout<<i+1;
        newline;
        flag = true;
      }
    }
    if(!flag){
      cout<<0;
      newline;
      return;
    }
}

int32_t main()
{
#ifdef ONLINE_JUDGE
    auto begin = chrono::high_resolution_clock::now();
    fastIO;
#endif

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

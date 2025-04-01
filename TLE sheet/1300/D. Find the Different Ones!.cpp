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
#define ia(a, n)                                                               \
  int a[n];                                                                    \
  f(i, n) cin >> a[i]
#define iv(v, n)                                                               \
  vector<int> v(n);                                                            \
  f(i, n) cin >> v[i]
#define vout(v)                                                                \
  for (auto i : v) {                                                           \
    std::cout << i << " ";                                                     \
  }
#define INF INT64_MAX
#define fastIO                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout.precision(numeric_limits<double>::max_digits10);
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define newline cout << endl
#define all(v) (v).begin(), (v).end()

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
int fact(int n) {
  if (n == 0)
    return 1;
  long res = 1;
  for (int i = 2; i <= n; i++)
    res = res * i;
  return res;
}
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }

// Main
// Function to solve a single test case
void solve() {
    int n; // n is long long due to #define
    cin >> n;
    iv(a, n);

    vi next_diff(n); 
    if (n > 0) {   
        next_diff[n - 1] = n; 
    }

    // Iterate from the second-to-last element down to the first element
    for (int i = n - 2; i >= 0; --i) {
        if (a[i + 1] != a[i]) {
            // If the next element is different, its index is the answer for i
            next_diff[i] = i + 1; // Store the 0-based index
        } else {
            // If the next element is the same, propagate the result from the right
            next_diff[i] = next_diff[i + 1];
        }
    }

    int q; 
    cin >> q;
    f(k, q) {               
        int l, r;           
        cin >> l >> r;
        int start_idx = l - 1;

        // Get the precomputed 0-based index of the first element different from a[start_idx]
        int diff_idx = next_diff[start_idx]; // diff_idx is long long

        // Check if this different element's index falls within the 1-based range [l, r].
        // In 0-based terms, this means diff_idx should be <= r-1.
        // Equivalently, check if diff_idx < r.
        if (diff_idx < r) {
            // A differing element is found within the range.
            // Output the 1-based indices: l (for start_idx) and diff_idx + 1.
            cout << l << " " << diff_idx + 1 << endl; // Use endl macro for newline
        } else {
            // No differing element found up to index r-1. All elements a[l...r] are the same.
            cout << -1 << " " << -1 << endl; // Output -1 -1
        }
    }
    newline;
}

int32_t main() {
#ifdef ONLINE_JUDGE
  auto begin = chrono::high_resolution_clock::now();
  fastIO;
#endif

  int t;
  cin >> t;
  // t = 1;
  while (t--) {
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

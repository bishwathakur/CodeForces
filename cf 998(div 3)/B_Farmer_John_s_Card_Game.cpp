#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pb push_back
#define pii pair<int, int>
#define f(i, n) for (int i = 0; i < n; i++)
#define fo(i, a, b) for (int i = a; i < b; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define INF INT64_MAX
int M = 1000000007;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define newline cout << endl
#define vpii vector<pair<int, int>>

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);

    f(i, n)
    {
        f(j, m)
        {
            int x;
            cin >> x;
            a[i].pb(x);
        }
    } // input

    f(i, n)
    {
        sort(a[i].begin(), a[i].end());
    } // 1st sort

    vpii order(n);
    f(i, n)
    {
        order[i] = {a[i][0], i};
    } // 1st time chance
    sort(order.begin(), order.end());

    vector<int> res; // answer
    for (auto &cow : order)
    {
        res.pb(cow.second);
    }

    int lastcard = -1;
    f(i, m)
    {
        f(j, n)
        {
            int cowindex = res[j];
            if (a[cowindex].empty()) // edge case
            {
                cout << -1;
                newline;
                return;
            }

            // updation
            int currcard = a[cowindex][0];
            if (currcard > lastcard)
            {
                lastcard = currcard;                    // update
                a[cowindex].erase(a[cowindex].begin()); // Remove the top card
            }
            else
            {
                cout << -1;
                newline;
                return;
            }
        }
    }
    for (auto i : res)
    {
        cout << i + 1 << " ";
    }
    newline;
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
    return 0;
}

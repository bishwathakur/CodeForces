#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
#define yes cout "YES\n"
#define no cout "NO\n"
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    int a[n];    \
    f(i, n) cin >> a[i]
#define iv(v, n)      \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define newline cout << endl

void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    f(i, n)
    {
        st.insert(i + 1);
    }
    vector<int> ans(n);
    int p = k - 1;
    while (p < n)
    {
        ans[p] = *st.begin();
        st.erase(st.begin());
        p += k;
    }
    f(i, n)
    {
        if (ans[i])
        {
            cout << ans[i] << " ";
        }
        else
        {
            cout << *st.begin() << " ";
            st.erase(st.begin());
        }
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
}

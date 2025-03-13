// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long int
// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// #define pb push_back
// #define pii pair<int, int>
// #define f(i, n) for (int i = 0; i < n; i++)
// #define fo(i, a, b) for (int i = a; i < b; i++)
// #define ia(a, n) \
//     int a[n];    \
//     f(i, n) cin >> a[i]
// #define iv(v, n)      \
//     vector<int> v(n); \
//     f(i, n) cin >> v[i]
// #define INF INT64_MAX
// int M = 1000000007;
// #define fastIO                   \
//     ios::sync_with_stdio(false); \
//     cin.tie(NULL);               \
//     cout.tie(NULL);              \
//     cout.precision(numeric_limits<double>::max_digits10);
// #define newline cout << endl
// #define vpii vector<pair<int, int>>

// void solve()
// {
//     int a, b;
//     cin >> a >> b;
//     int xk, yk;
//     cin >> xk >> yk;
//     int xq, yq;
//     cin >> xq >> yq;

//     vpii king;
//     vpii queen;

//     auto push_unique = [](vpii &vec, pii coord)
//     {
//         if (find(vec.begin(), vec.end(), coord) == vec.end())
//         {
//             vec.pb(coord);
//         }
//     };

//     push_unique(king, {xk + a, yk + b});
//     push_unique(king, {xk + a, yk - b});
//     push_unique(king, {xk - a, yk + b});
//     push_unique(king, {xk - a, yk - b});
//     push_unique(king, {xk + b, yk + a});
//     push_unique(king, {xk + b, yk - a});
//     push_unique(king, {xk - b, yk + a});
//     push_unique(king, {xk - b, yk - a});

//     push_unique(queen, {xq + a, yq + b});
//     push_unique(queen, {xq + a, yq - b});
//     push_unique(queen, {xq - a, yq + b});
//     push_unique(queen, {xq - a, yq - b});
//     push_unique(queen, {xq + b, yq + a});
//     push_unique(queen, {xq + b, yq - a});
//     push_unique(queen, {xq - b, yq + a});
//     push_unique(queen, {xq - b, yq - a});

//     int count = 0;
//     for (auto &k : king)
//     {
//         for (auto &q : queen)
//         {
//             if (k == q)
//             {
//                 count++;
//             }
//         }
//     }

//     cout << count;
//     newline;
// }

// int32_t main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }

//! use set directly

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
#define spii set<pair<int, int>>

void solve()
{
    int a, b;
    cin >> a >> b;
    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;

    spii king;
    spii queen;

    king.insert({xk + a, yk + b});
    king.insert({xk + a, yk - b});
    king.insert({xk - a, yk + b});
    king.insert({xk - a, yk - b});
    king.insert({xk + b, yk + a});
    king.insert({xk + b, yk - a});
    king.insert({xk - b, yk + a});
    king.insert({xk - b, yk - a});

    queen.insert({xq + a, yq + b});
    queen.insert({xq + a, yq - b});
    queen.insert({xq - a, yq + b});
    queen.insert({xq - a, yq - b});
    queen.insert({xq + b, yq + a});
    queen.insert({xq + b, yq - a});
    queen.insert({xq - b, yq + a});
    queen.insert({xq - b, yq - a});

    int count = 0;
    for (auto &k : king)
    {
        for (auto &q : queen)
        {
            if (k == q)
            {
                count++;
            }
        }
    }

    cout << count;
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



// // #include <bits/stdc++.h>
// // using namespace std;
// // #define endl "\n"
// // #define int long long int
// // #define yes cout << "YES\n"
// // #define no cout << "NO\n"
// // // #define pb push_back
// // #define pii pair<int, int>
// // #define f(i, n) for (int i = 0; i < n; i++)
// // #define fo(i, a, b) for (int i = a; i < b; i++)
// // #define ia(a, n) \
// //     int a[n];    \
// //     f(i, n) cin >> a[i]
// // #define iv(v, n)      \
// //     vector<int> v(n); \
// //     f(i, n) cin >> v[i]
// // #define INF INT64_MAX
// // int M = 1000000007;
// // #define fastIO                   \
// //     ios::sync_with_stdio(false); \
// //     cin.tie(NULL);               \
// //     cout.tie(NULL);              \
// //     cout.precision(numeric_limits<double>::max_digits10);
// // #define newline cout << endl

// // void solve()
// // {
// //     int n;
// //     cin >> n;
// //     vector<int> a(n), b(n), c(n);
// //     vector<pair<int, int>> pa(n), pb(n), pc(n);
// //     f(i, n)
// //     {
// //         cin >> a[i];
// //         pa[i] = {a[i], i};
// //     }
// //     f(i, n)
// //     {
// //         cin >> b[i];
// //         pb[i] = {b[i], i};
// //     }
// //     f(i, n)
// //     {
// //         cin >> c[i];
// //         pc[i] = {c[i], i};
// //     }
// //     sort(pa.rbegin(), pa.rend());
// //     sort(pb.rbegin(), pb.rend());
// //     sort(pc.rbegin(), pc.rend());
// //     int maxi = INT_MIN;
// //     f(i, 3)
// //     {
// //         f(j, 3)
// //         {
// //             f(k, 3)
// //             {
// //                 if (pa[i].second != pb[j].second && pb[j].second != pc[k].second && pc[k].second != pa[i].second)
// //                 {
// //                     maxi = max(maxi, pa[i].first + pb[j].first + pc[k].first);
// //                 }
// //             }
// //         }
// //     }
// //     cout << maxi;
// //     newline;
// // }

// // int32_t main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
// //     int t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         solve();
// //     }
// // }

// //! DP SOLUTION

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

// void solve()
// {
//     int n;
//     cin >> n;
//     iv(a, n);
//     iv(b, n);
//     iv(c, n);

//     int mask = 0;
//     //^ Row 1,2,3 all -> 111
//     //^ Row 1,2       -> 011
//     //^ Row 1         -> 001

//     int dp[n][7];

//     //
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


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to compute the maximum number of friends for a single test case
ll compute_max_friends(int n, const vector<ll>& a, const vector<ll>& b, const vector<ll>& c) {
    // Initialize DP array: dp[mask]
    // mask ranges from 0 to 7 (000 to 111)
    // We only need to keep track of the previous state
    vector<ll> prev_dp(8, -1e18);
    prev_dp[0] = 0; // Starting with no activities performed

    for(int day = 0; day < n; ++day){
        // Initialize current DP for this day
        vector<ll> curr_dp(8, -1e18);
        
        for(int mask = 0; mask < 8; ++mask){
            if(prev_dp[mask] == -1e18) continue; // Skip impossible states
            
            // Option 1: Do nothing on this day
            curr_dp[mask] = max(curr_dp[mask], prev_dp[mask]);
            
            // Option 2: Assign Skiing if not done yet
            if(!(mask & 1)){
                int new_mask = mask | 1;
                curr_dp[new_mask] = max(curr_dp[new_mask], prev_dp[mask] + a[day]);
            }
            
            // Option 3: Assign Movie if not done yet
            if(!(mask & 2)){
                int new_mask = mask | 2;
                curr_dp[new_mask] = max(curr_dp[new_mask], prev_dp[mask] + b[day]);
            }
            
            // Option 4: Assign Board Games if not done yet
            if(!(mask & 4)){
                int new_mask = mask | 4;
                curr_dp[new_mask] = max(curr_dp[new_mask], prev_dp[mask] + c[day]);
            }
        }
        
        // Update prev_dp for the next day
        prev_dp = curr_dp;
    }
    
    // The answer is the maximum friends with all three activities done (mask = 7)
    return prev_dp[7];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); // Fast input/output

    int t;
    cin >> t; // Number of test cases

    while(t--){
        int n;
        cin >> n; // Number of days

        // Read the number of friends for each activity on each day
        vector<ll> a(n), b(n), c(n);
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        for(auto &x : c) cin >> x;

        // Compute and output the result for the current test case
        ll result = compute_max_friends(n, a, b, c);
        cout << result << "\n";
    }

    return 0;
}
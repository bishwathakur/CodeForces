// #include <bits/stdc++.h>
// #include <string>
// using namespace std;
// #define endl "\n"
// #define int long long int

// int isok(string s,int m) {
//     int n = s.size();
//     int count=0;
//     string::size_type pos = 0;
//     string finding( m, '0');//!new
//     while((pos = s.find(finding,pos))!=string::npos) {
//         count++;
//         pos+=finding.size();
//     }
//     return count;
// }
// void solve() {
//     int n,m,k;cin>>n>>m>>k;
//     //code here
//     string s;cin>>s;
//     // cout<<isok(s,m)*k<<endl;
//     if(isok(s,m)==0) {
//         cout<<0<<endl;
//         return;
//     }
//     cout<<isok(s,m)<<endl;

    
// }

// int32_t main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl "\n"
// #define int long long

// int countIntervals(string &s, int m) {
//     int n = s.size();
//     int count = 0;
//     if(s[i]=='0') {
//         count++;
//     }
//     return count;
// }

// void solve() {
//     int n, m, k;
//     cin >> n >> m >> k;
//     string s;
//     cin >> s;

//     // int operations = 0;

//     // while (countIntervals(s, m) > 0) {
//     //     int best_pos = -1, min_remaining = INT_MAX;

//     //     for (int i = 0; i <= n - k; i++) {
//     //         string temp = s;
//     //         for (int j = 0; j < k; j++) {
//     //             temp[i + j] = '1';
//     //         }
//     //         int remaining = countIntervals(temp, m);
//     //         if (remaining < min_remaining) {
//     //             min_remaining = remaining;
//     //             best_pos = i;
//     //         }
//     //     }

//     //     for (int j = 0; j < k; j++) {
//     //         s[best_pos + j] = '1';
//     //     }
//     //     operations++;
//     // }

//     cout <<operations << endl;
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t; cin >> t;
//     int ct=0;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    int count=0, streak=0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            streak++;
        } else {
            streak=0;
        }
        if(streak==m) {
            count++;
            streak=0;
            if(k>1) {
                i+=m-1;
            }
        }
    }

    cout << count << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}



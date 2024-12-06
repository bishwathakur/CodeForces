#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int curr = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int x=0;
    for (int i = 0; i < n; i++) {
        curr += s[i].size();
        if (curr > m) {
            cout << x << endl;
            return;
        }else{
            x++;
        }
    }
    cout << n << endl;
    return;
}

int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

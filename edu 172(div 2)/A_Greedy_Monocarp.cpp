#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum=0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum+=a[i];
    }

    sort(a.rbegin(), a.rend());
    
    int i= 0;
    while (i < n) {
        if (k >= a[i]){
          k-=a[i];
          i++;
        } 
        else break;
        if (k==0) {
            cout << 0 << endl;
            return;
        }
    }
    cout << k << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    int a,b;cin>>a>>b;
    int hcf=__gcd(a,b);
    cout<<(a*b)/hcf<<endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

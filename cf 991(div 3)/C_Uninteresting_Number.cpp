#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    string strnum;cin>>strnum;
    map<char, int> digcnt;
    
    for (char ch : strnum) {
        if (ch == '2' || ch == '3') {
            digcnt[ch]++;
        }
    }
    // cout<<"digcnt['2']:"<<digcnt['2']<<endl;
    // cout<<"digcnt['3']:"<<digcnt['3']<<endl;
    
    int sum = 0;
    for (char ch : strnum) {
        sum += ch - '0';
    }
    // cout<<"sum:"<<sum<<endl;
    
    if (sum % 9 == 0) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i <= digcnt['2']; i++) {
        for (int j = 0; j <= digcnt['3']; j++) {
            int extra_sum = 2 * i + 6 * j;
            if (i == 0 && j == 0) continue; 
            if ((sum + extra_sum) % 9 == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

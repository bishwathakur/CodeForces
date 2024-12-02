#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> alice, bob;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                alice.push_back(i);
            } else {
                bob.push_back(i);
            }
        }
        
        int alice_score = 0, bob_score = 0;
        int groups = 0;
        int alice_index = 0, bob_index = 0;
        
        while (bob_index < bob.size()) {
            groups++;
            while (alice_index < alice.size() && alice[alice_index] < bob[bob_index]) {
                alice_score += groups - 1;
                alice_index++;
            }
            
            while (bob_index < bob.size() && (alice_index == alice.size() || bob[bob_index] < alice[alice_index])) {
                bob_score += groups - 1;
                bob_index++;
            }
            
            if (bob_score - alice_score >= k) {
                cout << groups << endl;
                break;
            }
        }
        
        if (bob_score - alice_score < k) {
            cout << -1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

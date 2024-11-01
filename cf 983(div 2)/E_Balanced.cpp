#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        // Check if balancing is possible
        if (sum % n != 0) {
            cout << -1 << endl;
            continue;
        }

        int target = sum / n;
        vector<int> operations(n, 0);

        bool possible = true;
        for (int i = 0; i < n; i++) {
            int diff = a[i] - target;
            if (diff % 2 != 0) {
                possible = false;
                break;
            }
            operations[i] = diff / 2;
        }

        if (!possible) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                cout << operations[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int minChanges(const string& a, const string& b, const string& c) {
    int n = a.size();
    int m = b.size();
    int res = 0;

    vector<int> posA(n + m + 1, 0);
    vector<int> posB(n + m + 1, 0);

    for (int i = 0; i < n; i++) {
        posA[i + 1] = posA[i] + (a[i] == c[i] ? 0 : 1);
    }

    for (int i = 0; i < m; i++) {
        posB[i + 1] = posB[i] + (b[i] == c[i + n] ? 0 : 1);
    }

    for (int i = 0; i <= n + m; i++) {
        res = max(res, min(posA[i], posB[n + m - i]));
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;

        cout << minChanges(a, b, c) << endl;
    }

    return 0;
}
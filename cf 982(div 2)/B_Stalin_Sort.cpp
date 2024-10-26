#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

vector<int> stalinsort(vector<int> &a) {
    vector<int> b;
    if (!a.empty()) {
        b.push_back(a[0]);
    }
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > b.back()) {
            b.push_back(a[i]);
        }
    }
    return b;
}
bool isDescending(const vector<int> &a) {
    for (int i = 0; i < a.size() - 1; ++i) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];//?input array

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }  
        //! If size of array is 1 then it is already sorted

        vector<int> defltsort = stalinsort(a);
        if(isDescending(defltsort)) {
            cout << 0 << endl;
        }
        //!for default sorted descending

        // vector<int> main;
        // for (int i = 0; i < n - 1; i++) {  // Loop until n-1 to prevent out-of-bounds
        //     if (a[i + 1] <= a[i])
        //         main.push_back(a[i]);
        // }
        // if (main.empty() || main.back() != a[n - 1]) {
        //     main.push_back(a[n - 1]);
        // }

        // cout << a.size() - main.size() << endl;
        int rem=0;
        vector<int> modified = a;
        for (int i = 1; i < n; i++){
            if(modified[i] > modified[i-1]){
                modified.erase(modified.begin() + i);
                if(isDescending(stalinsort(modified))){
                    cout<<++rem<<endl;
                    continue;
                }
            }
        }
    }
    return 0;
}

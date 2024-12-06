// #include <bits/stdc++.h>
// using namespace std;
// #define endl "\n"
// #define int long long int

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         sum += a[i];
//     }
    

//     if (sum % n != 0) {
//         cout << "NO" << endl;
//         return;
//     }
    
//     int target = sum / n;
//     for (int i = 1; i < n - 1; i++) {
//         int diff=(a[i-1]-target);
//         if(diff==0){
//             continue;
//         }else{
//             a[i-1]-=diff;
//             a[i+1]+=diff;
//         }
//     }
    // if(a[n-1]==target) {
    //     cout << "YES" << endl;
    // } else {
    //     cout << "NO" << endl;
    // }
// }

// int32_t main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
// }


#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
 
    // If the sum is not divisible by n, it's impossible to make all elements equal
    if (sum % n != 0) {
        cout << "NO" << endl;
        return;
    }
 
    int target = sum / n;
 
    for (int i = 1; i < n - 1; i++) {
        int diff = a[i-1] - target;
        if (diff != 0) {
            a[i - 1] -= diff;
            a[i + 1] += diff;
        }
    }
    if(a[n-1]==target) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
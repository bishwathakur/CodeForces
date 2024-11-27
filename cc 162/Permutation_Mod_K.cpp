#include <bits/stdc++.h>
using namespace std;
#define endl "\n";


//! Bassically we have to print the permutation of 1 to n such that the 
//& Value(->x) mod k!= Index(->y) mod k
//^ That equality only happens when (x-y) is div by k, so we have to print the permutation such that (x-y) is not div by k
//* So we can print the permutation in such a way that the difference between is 1 that only is div by k(=1), therfore index =i+1 and value =i and vice versa..



void solve() {
    int n, k;
    cin >> n >> k;
    //*cause in 312-> 3 is diff bw index and value is 2 which is not div by k if k>2
    if (k == 1 || (n%2==1 && k==2)) {
        cout << -1 << endl;
        return;
    }
    //? So when even is n then do like this (2, 1),(4, 3),(6, 5).....
    if (n%2==0){
        for (int i = 0; i < n; i+=2) {
            cout<< i+2 << " "<<i+1<<" ";
        }
    //? When n is odd then do like this (3, 1, 2),(5, 4).....
    } else {
        cout<< "3 1 2 ";
        for (int i = 3; i < n; i+=2) {
            cout<<i+2<<" "<<i+1<<" ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

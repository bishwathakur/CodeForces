#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void solve(){
    int n;cin>>n;
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++)cin>>a[i];
    sort(a.rbegin(),a.rend());
    
    vector<int> ans(n,0);
    
    ans[n-1]=a[n-2]/2;
    for(int i=n-2;i>=0;i--){
        ans[i]+=a[i]-ans[i+1];
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
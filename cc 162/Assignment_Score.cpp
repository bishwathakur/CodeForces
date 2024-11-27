#include <bits/stdc++.h>
using namespace std;
#define endl "\n";

void solve(){
    int n;cin>>n;
    vector<int> a(n);
    int scored=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        scored+=a[i];
    }
    int tot =100*(n+1);
    int passing = tot * 0.5;
    if(passing<=scored){
        cout<<0<<endl;
    }else if((passing-scored)<=100){cout<<passing-scored<<endl;}
    else cout<<-1<<endl;

}
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
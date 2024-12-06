#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vector<int> p;
    int y=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
           y++; 
        }else{
            y--;
        }
        if(i>0){
            p.push_back(y);
        }
    }//!     N
    
    sort(p.rbegin(),p.rend());//!      NlogN

    int m=1,sum=0;
    for(auto i:p){
        sum+=i;
        m++;
        if(sum>=k){
            cout<<m<<endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

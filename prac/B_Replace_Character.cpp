#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    
    int n;cin>>n;
    string s;cin>>s;
    //code here
    if(n==1){
        cout<<s<<endl;
        return;
    }
    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    // for(auto x:mp){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    vector<pair<char,int>>v(mp.rbegin(),mp.rend());

    sort(v.begin(), v.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    });

    // for(auto x: v){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    char main=v[0].first;
    char least=v[v.size()-1].first;
    int index=s.find(least);
    s[index]=main;
    cout<<s<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    //code here
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    vector<pair<int, int>> freqVec(mp.begin(), mp.end());

    sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    });

    // for (const auto& p : freqVec) {
    //     cout << p.first << " " << p.second << endl;
    // }
    

    int ans = 0;
    bool myChance = true;
    
    for (int i = 0; i < freqVec.size(); i++) {
        pair<int, int>& p = freqVec[i];
        int points = (p.second == 1) ? 2 : 1;
    
        bool pointsUsed = false; 
    
        while (p.second > 0) {
            if (myChance) {
                if (p.second == 1 && !pointsUsed) {
                    ans += points;
                    if(points==1)points=0;
                    pointsUsed = true; 
                    p.second--; 
                } else {
                    //here error since points is not used but not point
                    ans += points;
                    if(points==1)points=0;
                    p.second--; 
                }
            } else { 
                p.second--; 
            }
    
            myChance = !myChance;
    
            if (p.second == 0) {
                break;  
            }
        }
    }
    cout<<ans<<endl;
    
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

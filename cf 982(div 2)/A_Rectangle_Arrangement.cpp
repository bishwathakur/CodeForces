#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>> v(n);
        int maxw=0,maxh=0;
        for (int i = 0; i < n; i++){
            int w,h;
            cin>>w>>h;
            maxw=max(maxw,w);
            maxh=max(maxh,h);
        }
        cout<<2*(maxw+maxh)<<endl;
        
    }
}
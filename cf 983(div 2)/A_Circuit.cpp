#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int32_t main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(2*n);
        int zeroes=0,ones=0;
        for (int i = 0; i < 2*n; i++){
            cin>>a[i];
            if(a[i]==0) zeroes++;
            else ones++;
        }
        if(zeroes==0 || ones==0){
            cout<<0<<" "<<0<<endl;
            continue;
        }
        int maxi=0,mini=0;
        if(ones%2==0){
            mini=0;
        }else {
            mini=1;
        }
        if(zeroes>ones){
            maxi=ones;
        }else{
            maxi=zeroes;
        }
        
        cout<<mini<<" "<<maxi<<endl;
        
    }
}
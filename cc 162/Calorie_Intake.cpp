#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define int long long int

void solve(){
    int x,y,z;cin>>x>>y>>z;
    //code here
    int done=y*z;
    if(x<done){
        cout<<-1<<endl;
    }else{
        cout<<x-done<<endl;
    }
    
}
int32_t main() {
    // your code goes here
    solve();
}
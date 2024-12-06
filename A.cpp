#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
    string s;cin>>s;
    int n=s.size();
    int v=0,c=0,alt=0;
    for (int i = 0; i < n; i++){
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            v++;
        }else if(i!=n-1 && s[i]=='N' && s[i+1]=='G'){
            c++;
            i++;
        }else if(s[i]=='Y'){
            alt++;  
        }else{
            c++;
        }
    }
    cout<<"Vowels: "<<v<<endl;
    cout<<"Consonants<: "<<c<<endl;
    cout<<"Alt: "<<alt<<endl;
    int total=v+c+alt;
    cout<<"Total: "<<total<<endl;

}

int32_t main() {
    solve();
}

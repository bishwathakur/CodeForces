#include<bits/stdc++.h>
using namespace std;
bool finder(string s){
    size_t found = s.find("1100");
    if(found!=string::npos){
        return true;
    }
    return false;
}

int main(){
    string s="1100000";
    string ans=(finder(s))?"YES":"NO";
    cout<<ans;
    return 0;
}
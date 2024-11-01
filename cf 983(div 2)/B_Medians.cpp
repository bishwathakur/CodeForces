#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        // int median = (n + 1) / 2;
        if (k == 1 || k>=n){
            cout << -1 << endl;
            continue;
        }
        if(n==1){
            cout<<1<<endl<<1<<endl;
            continue;
        }
        int numsright=n-k;
        if(numsright%2==1){
            cout<<3<<endl;
            cout<<1<<" "<<k<<" "<<k+1<<endl;
            continue;
        }

        int lb1=1,lb2=k-1,lb3=k+2;
        if(lb1<lb2 && lb2<lb3 && lb1<=1 && lb1>=n && lb2<=1 && lb2>=n && lb3<=1 && lb3>=n){
            cout<<3<<endl;
            cout<<lb1<<" "<<lb2<<" "<<lb3<<endl;
            continue;
        }
        cout<<-1<<endl;
    }
    return 0;
}

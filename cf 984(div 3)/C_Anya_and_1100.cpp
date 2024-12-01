#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long


//* 1sec = 10e7


bool finder(const string &s)
{
    return s.find("1100") != string::npos; //&  O(|S|)
}

void solve()
{
}

int32_t main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) //* O(T*|S|*Q) = O(T*|S|Q)    T<10e4, |S|<2*10e5, Q<2*10e5
    {
        string s; cin >> s;
        int q; cin >> q;

        for (int m = 0; m < q; m++) //* O(Q) =
        {
            int i;
            char v;
            cin >> i >> v;
            s[i - 1] = v;

            if (finder(s))
                cout << "YES" << endl; //* O(|S|)  * O(Q) = O(|S|Q) = 4*10e10
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
//! TLE

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s = " " + s;
        int q;
        cin >> q;
        int len = s.size() - 1;
        int arr[len + 1];
        for (int i = 0; i <= len; i++)
            arr[i] = 0;
        int ct = 0;
        for (int i = 1; i <= len - 3; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                ct++;
                arr[i] = 1;
            }
        }
        for (int i = 0; i < q; i++)
        {
            int x, y;
            cin >> x >> y;
            if (s[x] == '1' && y == 0)
            {
                if (x <= len - 3 && arr[x] == 1)
                {
                    arr[x] = 0;
                    ct--;
                }
                else if (x >= 2 && x <= len - 2 && arr[x - 1] == 1)
                {
                    arr[x - 1] = 0;
                    ct--;
                }
                if (x >= 3 && x <= len - 1 && s[x + 1] == '0' && s[x - 1] == '1' && s[x - 2] == '1')
                {
                    arr[x - 2] = 1;
                    ct++;
                }
                else if (x >= 4 && x <= len && s[x - 1] == '0' && s[x - 2] == '1' && s[x - 3] == '1')
                {
                    arr[x - 3] = 1;
                    ct++;
                }
            }
            else if (s[x] == '0' && y == 1)
            {
                if (x <= len - 1 && x >= 3 && arr[x - 2] == 1)
                {
                    arr[x - 2] = 0;
                    ct--;
                }
                else if (x >= 4 && x <= len && arr[x - 3] == 1)
                {
                    arr[x - 3] = 0;
                    ct--;
                }
                if (x <= len - 3 && s[x + 1] == '1' && s[x + 2] == '0' && s[x + 3] == '0')
                {
                    arr[x] = 1;
                    ct++;
                }
                else if (x <= len - 2 && x >= 2 && s[x - 1] == '1' && s[x + 1] == '0' && s[x + 2] == '0')
                {
                    arr[x - 1] = 1;
                    ct++;
                }
            }
            s[x] = '0' + y;
            // cout<<ct<<"\n";
            // cout<<s<<"\n";
            if (ct > 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

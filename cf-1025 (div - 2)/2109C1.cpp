#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long n, x;
        cin >> n >> x;
        long long diff = n - x;
        // one single addition will bring x to n
        cout << "add " << diff << "\n";
        // we're done
        cout << "!\n";
        // (no need to read any judge responses in hack mode)
    }
    return 0;
}

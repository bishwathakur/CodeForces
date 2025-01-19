#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sol()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    vector<bool> used(200001, false); // To track if a number is already used
    vector<int> freq(200001, 0);      // To track occurrences of each number
    int nextUnused = 1;               // Smallest unused positive integer

    // Mark the numbers in the input as used
    for (int i : v)
    {
        used[i] = true;
    }

    // Output result
    for (int i : v)
    {
        if (freq[i] == 0)
        {
            // Number is not repeated yet
            cout << i << " ";
            freq[i]++;
        }
        else
        {
            // Find the smallest unused positive integer
            while (used[nextUnused])
            {
                nextUnused++;
            }
            cout << nextUnused << " ";
            used[nextUnused] = true; // Mark it as used
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        sol();
        cout << '\n';
    }
    return 0;
}
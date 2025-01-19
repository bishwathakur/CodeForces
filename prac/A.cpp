// #include <iostream>
// #include <string>
// #include <cmath>

// using namespace std;

// long long fact(int x)
// {
//     if (x == 0)
//         return 1;
//     return x * fact(x - 1);
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         n = min(n, 7);

//         int factorial = fact(n);

//         // Create a string with k digits repeated factorial times
//         string repeated_k = string(factorial, '0' + k);

//         // Convert the string to an integer
//         int result = stoi(repeated_k);

//         for (int i = 1; i < 10; i += 2)
//         {
//             if (result % i == 0)
//             {
//                 cout << i << " ";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate factorial
long long fact(int x)
{
    if (x == 0)
        return 1;
    return x * fact(x - 1);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        // Limit `n` to 7 as factorials grow very large beyond this
        n = min(n, 7);
        long long factorial = fact(n);

        // Create the repeated number string
        string repeated_k;
        for (long long i = 0; i < factorial; ++i)
        {
            repeated_k += to_string(k);
                }

        // Handle extremely large numbers by processing modulo results
        long long s = 0;
        for (char c : repeated_k)
        {
            s = (s * 10 + (c - '0')) % 2520; // 2520 is LCM of numbers 1 to 9
        }

        // Check divisibility for odd numbers
        for (int i = 1; i < 10; i += 2)
        {
            if (s % i == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

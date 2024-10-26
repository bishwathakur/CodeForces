#include <iostream>
#include <vector>

using namespace std;

// Function to perform Stalin sort
vector<int> stalinsort(const vector<int> &a) {
    vector<int> b;
    if (!a.empty()) {
        b.push_back(a[0]); // Start with the first element
    }

    // Iterate through the input array
    for (int i = 1; i < a.size(); i++) {
        if (a[i] > b.back()) {
            b.push_back(a[i]); // Only add if greater than the last element in b
        }
    }
    return b;
}

int main() {
    // Test cases for stalinsort
    vector<vector<int>> test_cases = {
        {5 ,4 ,4 ,2 ,2},    // Mixed values
        {5, 6, 7, 8, 9},    // Already sorted (ascending)
        {9, 8, 7, 6, 5},    // Already sorted (descending)
        {1, 2, 3, 4, 5},    // Already sorted (ascending)
        {1, 2, 1, 2, 3},    // Mixed values with repeats
        {3, 2, 4, 1, 5},    // Mixed values
    };

    // Run tests
    for (const auto &test_case : test_cases) {
        cout << "Input: ";
        for (int num : test_case) {
            cout << num << " ";
        }
        cout << "\nStalin Sort Output: ";
        
        vector<int> sorted_output = stalinsort(test_case);
        
        // Print the output of the stalinsort
        for (int num : sorted_output) {
            cout << num << " ";
        }
        cout << endl << endl;
    }

    return 0;
}

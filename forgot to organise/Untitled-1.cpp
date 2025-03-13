#include <iostream>
#include <cmath> // For built-in floor and ceil functions

// Custom floor division function
int floor_division(int a, int b)
{
    return (a / b) - ((a % b < 0 && a % b != 0) ? 1 : 0);
}

// Custom ceiling division function
int ceiling_division(int a, int b)
{
    // If perfectly divisible
    if (a % b == 0)
        return a / b;

    // For positive numbers or zero
    if (a >= 0)
        return (a + b - 1) / b;

    // For negative numbers
    return a / b;
}

// Alternative implementation using a single formula
int ceiling_division_alt(int a, int b)
{
    return (a + b - (a < 0 ? 0 : 1)) / b;
}

int main()
{
    // Test cases
    int test_cases[][2] = {
        {7, 3},  // Positive / Positive
        {10, 5}, // Evenly divisible
        {-7, 3}, // Negative / Positive
        {7, -3}, // Positive / Negative
        {-7, -3} // Negative / Negative
    };

    std::cout << "a/b\t| Floor\t| Ceiling\t| std::floor\t| std::ceil\n";
    std::cout << "-----------------------------------------------------\n";

    for (auto &test : test_cases)
    {
        int a = test[0];
        int b = test[1];

        // Calculate using our functions
        int floor_result = floor_division(a, b);
        int ceiling_result = ceiling_division(a, b);

        // Calculate using standard library for comparison
        double exact = static_cast<double>(a) / b;
        double std_floor = std::floor(exact);
        double std_ceil = std::ceil(exact);

        // Print results
        std::cout << a << "/" << b << "\t| "
                  << floor_result << "\t| "
                  << ceiling_result << "\t\t| "
                  << std_floor << "\t\t| "
                  << std_ceil << "\n";
    }

    return 0;
}

#include<iostream>      // Include input-output stream library for console output
#include<thread>        // Include thread library for multithreading
#include<chrono>        // Include chrono library for time-related functions
#include<algorithm>     // Include algorithm library (not used in this code)

using namespace std;    // Using standard namespace to avoid prefixing `std::`

typedef unsigned long long ull; // Define an alias `ull` for `unsigned long long` (for large numbers)

ull evenSum = 0;  // Global variable to store the sum of even numbers
ull oddSum = 0;   // Global variable to store the sum of odd numbers

/**
 * Function: thread_1
 * Purpose: Calculates the sum of even numbers in the given range.
 * Parameters:
 *   - start: Start of the range
 *   - end: End of the range
 */
void thread_1(ull start, ull end)
{
    for (ull i = start; i <= end; i++) // Loop from `start` to `end`
    {
        if (i % 2 == 0) // Check if the number is even
        {
            evenSum += i; // Add the even number to `evenSum`
        }
    }

    // // Print the sum of even numbers
    // cout << "Even Sum: " << evenSum << endl;
}

/**
 * Function: thread_2
 * Purpose: Calculates the sum of odd numbers in the given range.
 * Parameters:
 *   - start: Start of the range
 *   - end: End of the range
 */
void thread_2(ull start, ull end)
{
    for (ull i = start; i < end; i++) // Loop from `start` to `end`
    {
        if (i % 2 != 0) // Check if the number is odd
        {
            oddSum += i; // Add the odd number to `oddSum`
        }
    }

    this_thread::sleep_for(100ms); // Pause execution for 100 milliseconds (not necessary in this case)
    
    // Print the sum of even numbers
    cout << "Even Sum: " << evenSum << endl;
    // Print the sum of odd numbers
    cout << "Odd Sum: " << oddSum << endl;
}

int main()
{
    // Creating two threads that execute `thread_1` and `thread_2` functions concurrently
    thread t1(thread_1, 1, 1000); // Thread `t1` calculates the sum of even numbers
    thread t2(thread_2, 1, 1000); // Thread `t2` calculates the sum of odd numbers

    t1.join(); // Wait for `t1` to complete execution
    t2.join(); // Wait for `t2` to complete execution

    this_thread::sleep_for(500ms); // Pause the main thread for 500 milliseconds (not necessary)

    return 0; // Return 0 to indicate successful program execution
}

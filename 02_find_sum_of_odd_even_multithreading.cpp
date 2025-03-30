#include <iostream>      // Include input-output stream library for console output
#include <thread>        // Include thread library for multithreading
#include <chrono>        // Include chrono library for time-related functions

using namespace std;    
using namespace std::chrono; // Use chrono namespace for time functions
using namespace std::chrono_literals; // Enable literals like 100ms

typedef unsigned long long ull; 

ull evenSum = 0;  
ull oddSum = 0;   

void thread_1(ull start, ull end)
{
    for (ull i = start; i <= end; i++) 
    {
        if (i % 2 == 0) 
        {
            evenSum += i; 
        }
    }
}

void thread_2(ull start, ull end)
{
    for (ull i = start; i < end; i++) 
    {
        if (i % 2 != 0) 
        {
            oddSum += i; 
        }
    }

    std::this_thread::sleep_for(100ms); // Corrected syntax
}

int main()
{
    auto startTime = high_resolution_clock::now(); // Start time measurement

    // thread_1(1, 1000000000);
    // thread_2(1, 1000000000);
    thread t1(thread_1, 1, 1000000000); 
    thread t2(thread_2, 1, 1000000000); 

    t1.join(); 
    t2.join(); 

    auto endTime = high_resolution_clock::now(); // End time measurement
    auto duration = duration_cast<microseconds>(endTime - startTime); // Corrected syntax

    cout << "Total Duration: " << duration.count() << " microseconds" << endl; // Use .count() for output
    cout << "Even Sum: " << evenSum << endl;
    cout << "Odd Sum: " << oddSum << endl;

    return 0; 
}

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;

volatile int num = 0;


// Thread function 1: Increments `num` in an infinite loop
void thread_1()
{
    
    while(1) // Infinite loop
    {
        num++; // Increment the global variable `num`
        cout << "thread_1 Num: " << num << endl; // Print the current value of `num`
        this_thread::sleep_for(50ms); // Pause execution for 50 milliseconds
    }
}

// Thread function 2: Resets `num` to 0 when it reaches 50
void thread_2()
{
    while(1) // Infinite loop
    {
        if(num >= 50) // Check if `num` has reached 50 or more
        {
            cout << "Num reset" << endl; // Print reset message
            num = 0; // Reset `num` to 0
        }
        this_thread::sleep_for(50ms); // Pause execution for 50 milliseconds
    }
}


int main()
{
    thread t1(thread_1); // Creating a object for thread 
    thread t2(thread_2);

    t1.join();
    t2.join();

    t2.detach();
    t1.detach();

    this_thread::sleep_for(500ms);

    return 0;
}
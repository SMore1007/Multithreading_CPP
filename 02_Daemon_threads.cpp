#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;

// thread 1
void thread_1()
{
    while(1)
    {
        cout << "thread_1 is running" << endl;
        this_thread::sleep_for(100ms);
    }

}

// thread 2
void thread_2()
{
    while(1)
    {
        cout << "thread_2 is running" << endl;
        this_thread::sleep_for(200ms);
    }
}

int main()
{
    cout << "Main function start" << endl;
    thread t1(thread_1); // Creating a object for thread 
    thread t2(thread_2);

    /* wait till complete the threads of execution*/
    t1.join();
    t2.join();

    /* Dont wait till threads is comeplete, run the threads in background and execution thread go below*/
    // t2.detach();
    // t1.detach();

    this_thread::sleep_for(500ms);

    return 0;
}
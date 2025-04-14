#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;

void Daemon()
{
    while (1)
    {
        cout << "This is a Daemon thread 1 " << endl;
        this_thread::sleep_for(100ms);
    }
    
}

void Daemon2()
{
    while (1)
    {
        cout << "This is a Daemon thread 2 " << endl;
        this_thread::sleep_for(100ms);
    }
    
}
int main()
{
    thread t1(Daemon);  // Creating a thread object
    t1.detach();        // Run the daemon thread in background

    thread t2(Daemon2); // Create the thread 2
    t2.detach();        // run it in  background

    while (1){}
    
}
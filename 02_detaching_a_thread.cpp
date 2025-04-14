#include<iostream>  // i/o
#include<thread>    // for multithreading
#include<chrono>    // time related functions


using namespace std;
using namespace std::chrono;  // standard namespce for chrono

void task(void)
{

    while (1)
    {
        cout << "In thread" << endl;
        this_thread::sleep_for(seconds(1));
    }
}

int main()
{
    thread t(task); // thread initialization

    t.detach(); // Runs the t thread independantly

    while (1)
    {
        cout << "In main " << endl;

        this_thread::sleep_for(seconds(1));
    }
    
    return 0;

}


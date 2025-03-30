#include<iostream> // for input and output
#include<thread>   // for threading
#include<chrono>   // for time functions

using namespace std;  // for standad names

void _thread1()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "*";
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
}

void _thread2()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "o";
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
}


int main()
{
    thread worker1(_thread1);
    thread worker2(_thread2);

    worker1.join();  // Wait for the thread to finish
    worker2.join();
    cout<< "\n";
}
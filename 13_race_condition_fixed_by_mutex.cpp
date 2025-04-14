#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;
std::mutex mtx;

int counter = 0;

void increment(int num)
{
    for (int  i = 0; i < num; i++)
    {
        lock_guard<mutex> lock(mtx); // mutex as locking 
        counter++;
    }
}

int  main()
{
    int iteration = 100000;
    thread t1(increment, iteration);
    thread t2(increment, iteration);

    t1.join();
    t2.join();

    cout << "Final Counter value: " << counter << endl;

    return 0;
}
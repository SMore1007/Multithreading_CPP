#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
using namespace std::chrono;
std::mutex mtx;


void printsafe(int id)
{
    lock_guard<mutex> lock(mtx);  // Auto lock and unlock

    cout << "Thread " << id << " is running" << endl;
}

int main()
{
    thread t1(printsafe, 1);

    thread t2(printsafe, 2);

    t1.join();
    t2.join();

    return 0;
}
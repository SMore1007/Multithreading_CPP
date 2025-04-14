#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void worker(int number)
{
    cout << "Worker thread Number: " << number << endl;
}

int main()
{
    vector<thread> workers;

    for (int i = 0; i < 10; ++i)
    {
        thread t = thread(worker, i);  // 'worker' is function name
        workers.push_back(move(t));    // move the thread into the vector
    }

    
    for_each(workers.begin(), workers.end(), [](thread &t)   
    {
        assert(t.joinable());
        t.join();  // wait for thread to finish
    });

    return 0;
}

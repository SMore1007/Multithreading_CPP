#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

using namespace std::chrono;

// thread 1 
void printNumber(int start, int end)
{
    // for (int i = start; i <= end; i++)
    // {
    while(1)
    { 
        if(start != end)
        {
            cout << start << endl;
            this_thread::sleep_for(microseconds(10));
            start++;
        }
  
    }
    
        
    // }
    
}


int main()
{
    thread t1(printNumber, 10, 100); // Creating thread function name and passing arguments to a function

    //t1.join(); // wait for the thread to complete
    t1.detach();
    cout << "t1.detach() used\n";

    while (1)
    {
        /* code */
    }
    
    return 0;
}
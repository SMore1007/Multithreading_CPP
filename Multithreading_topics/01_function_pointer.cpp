#include<iostream>
#include<thread>

using namespace std;

void foo(int val)
{
    cout << "Function Pointer Thread, value: " << val << endl;
}

int main()
{
    int paramter = 50;

    thread t1(foo, paramter);

    t1.join();  // wait for the thread to finish

    return 0;
}
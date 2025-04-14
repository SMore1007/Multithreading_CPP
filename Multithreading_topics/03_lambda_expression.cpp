/*

Lambda expressions provide a concise way to define anonymous functions in C++. 
They can capture variables from their enclosing scope and are often used as 
callable objects for creating threads.
When launching a thread with a lambda, you pass the lambda itself to 
the std::thread constructor.

*/

#include<iostream>
#include<thread>
using namespace std;

int main()
{
    int para = 42;

    auto lambda = [para]
    {
        cout << "Lambda Expression Thread, value: " << para << endl;
    };
}
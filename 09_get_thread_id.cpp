#include<iostream>
#include<bits/stdc++.h>
#include<thread>
using namespace std;

void helloWorld()
{
    cout << "Hello World, ID: " << this_thread::get_id() << endl;
}

int main()
{
    thread t1(helloWorld);
    

    cout << "Main thread ID: " << this_thread::get_id() << endl;
    t1.detach();

    while(1)
    {
        // main loop
    }

    return 0;
}
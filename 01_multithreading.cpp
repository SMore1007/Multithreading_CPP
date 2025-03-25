// #include <iostream>
// #include <thread>

// using namespace std;

// void function1(char symbol) {
//     for (int i = 0; i < 20; i++) {
//         cout << symbol;
//     }
// }

// void function2(char symbol) {
//     for (int i = 0; i < 20; i++) {
//         cout << symbol;
//     }
// }

// int main() {
//     char s1 = '-';
//     char s2 = '+';

//     thread Worker1(function1, s1);
//     thread Worker2(function2, s2);

//     // Ensure both threads complete before exiting
//     Worker1.join();
//     Worker2.join();

//     system("pause>nul");
//     return 0;
// }


/******************************************************************/


#include<iostream> // for input and output
#include<thread> // for threading
#include<chrono> // for time functions

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

    worker1.join();
    worker2.join();
    cout<< "\n";
}
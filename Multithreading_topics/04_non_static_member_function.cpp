/*
    4. Non-Static Member Function

    Non-static member functions are part of a class and require an instance of the class to be called. 
    They can be used as callables for creating threads in C++. To launch a thread using a non-static member function, 
    you pass both the member function's pointer and an instance of the class to the std::thread constructor.

*/

#include<iostream>
#include<thread>
using namespace std;

class MyClass
{
    private:
        
    public:
        void memberFunction(int val)
        {
            cout << "This is member function " << val << endl;
        }
};

int main()
{
    int parameter = 50;
    MyClass class_obj; // class Object
    thread thread_obj(MyClass::memberFunction, &class_obj, 50);
    thread_obj.join();
    return 0;
}
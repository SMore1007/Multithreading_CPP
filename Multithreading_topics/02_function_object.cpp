#include <iostream>
#include <thread>
using namespace std;

class MyFunctor 
{
    public:
        void operator()(int value) 
        {
            cout << "Function Object Thread, Value: " << value << endl;
        }
};

int main()
{
    int param = 42;
    MyFunctor functor;
    thread thread_obj(functor, param);
    thread_obj.join();
    return 0;
}
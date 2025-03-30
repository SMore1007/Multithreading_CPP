#include <iostream>
#include <thread>
#include<chrono>
using namespace std;
using namespace std::chrono;

void callbackFunction(int result) {
    cout << "Callback executed with result: " << result << "\n";
}

void worker(void (*callback)(int)) {
    this_thread::sleep_for(chrono::seconds(2));
    int result = 42;
    callback(result); // Invoke callback function
}

int main() {
    thread t(worker, callbackFunction);
    t.join();
    return 0;
}

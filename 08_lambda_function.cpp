#include <iostream>
#include <thread>
#include <chrono>
#include <functional> 

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

// Thread function
void worker(function<void(int)> cb) {
    this_thread::sleep_for(seconds(2));
    cb(100);   // Call the callback with result
}

int main() {
    thread t(worker, [](int result) {
        cout << "Lambda callback received: " << result << "\n";
    });

    t.join();
    return 0;
}

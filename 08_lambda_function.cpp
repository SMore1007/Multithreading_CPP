#include <iostream>
#include <thread>
#include <chrono>
#include <functional>  // Missing header included

using namespace std;
using namespace std::chrono;

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

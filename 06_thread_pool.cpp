#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void task(int id) {
    cout << "Task " << id << " is running\n";
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(task, i); // Create multiple threads
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

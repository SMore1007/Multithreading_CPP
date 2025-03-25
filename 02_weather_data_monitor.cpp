#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

void RefreshForecast(map<string, int>& forecasteMap) // Pass by reference
{
    while (true)
    {
        cout<< "\n\n"<< endl;

        for (auto& item : forecasteMap) // Use reference to modify map elements
        {
            item.second++; // Update temperature
            cout << item.first << " - " << item.second << endl;
        }

        // Sleep for 2 seconds (2000ms instead of 20000ms)
        this_thread::sleep_for(1000ms);
    }
}

int main()
{
    map<string, int> forecasteMap = {
        {"Pune", 15},
        {"Mumbai", 20},
        {"Berlin", 18}
    };

    // Create a new thread and detach it
    thread bgWorker(RefreshForecast, ref(forecasteMap)); // Use ref() to pass by reference
    bgWorker.detach(); // Detach the thread so it runs independently

    system("Pause>nul"); // Keep the main thread alive (Windows only)
}

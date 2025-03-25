#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <queue>
#include <chrono>
#include <random>

using namespace std;

// Mutex and Condition Variable for synchronization
mutex mtx;
condition_variable cv;
queue<string> dataQueue;
bool stopLogging = false;

// Function to simulate sensor data generation
string getSensorData() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> tempDist(20, 30);
    static uniform_int_distribution<> humidityDist(40, 60);
    
    int temperature = tempDist(gen);
    int humidity = humidityDist(gen);

    return "Temperature: " + to_string(temperature) + "°C, Humidity: " + to_string(humidity) + "%";
}

// Producer thread - Generates sensor data
void sensorDataProducer() {
    while (!stopLogging) {
        this_thread::sleep_for(chrono::seconds(1));  // Simulate sensor delay
        string data = getSensorData();

        {
            lock_guard<mutex> lock(mtx);
            dataQueue.push(data);
        }

        cv.notify_one();  // Notify logger thread
    }
}

// Consumer thread - Logs data to a file
void dataLogger() {
    ofstream logFile("sensor_log.txt", std::ios::app);
    
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !dataQueue.empty() || stopLogging; });

        if (stopLogging && dataQueue.empty()) break;

        while (!dataQueue.empty()) {
            logFile << dataQueue.front() << endl;
            cout << "Logged: " << dataQueue.front() << endl;
            dataQueue.pop();
        }
    }
    
    logFile.close();
}

int main() {
    thread producer(sensorDataProducer);
    thread logger(dataLogger);

    this_thread::sleep_for(chrono::seconds(10));  // Run for 10 sec
    stopLogging = true;
    cv.notify_one();  // Ensure logger thread wakes up

    producer.join();
    logger.join();

    cout << "Logging Complete. Check 'sensor_log.txt'." << endl;
    return 0;
}


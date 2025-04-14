# Multithreading in C++

## Introduction
Multithreading in C++ is a programming technique that allows a program to execute multiple threads concurrently. Threads are lightweight processes that share the same memory space and can perform tasks independently, enhancing the program's efficiency and responsiveness. C++ provides libraries, like std::thread, for creating and managing threads. Multithreading is particularly useful for tasks that can be parallelized, such as handling multiple user requests or improving performance in multi-core processors.

## What is a Thread?
A thread is the smallest unit of execution within a process. A process can have multiple threads that share the same memory space but execute independently.

## Key Concepts in Multithreading
### 1. Creating Threads
Threads in C++ are created using the `std::thread` class from the `<thread>` library. There are multiple ways to create a thread:

#### Using a Function
```cpp
#include <iostream>
#include <thread>

void task()
{
    std::cout << "Thread is running" << std::endl;
}

int main()
{
    std::thread t1(task);
    t1.join(); // Wait for thread to finish
    return 0;
}
```

#### Using a Lambda Function

Lambda expressions provide a concise way to define anonymous functions in C++. They can capture variables from their enclosing scope and are often used as callable objects for creating threads. When launching a thread with a lambda, you pass the lambda itself to the std::thread constructor.

```cpp
#include <iostream>
#include <thread>

int main()
{
    std::thread t1([](){ std::cout << "Thread is running" << std::endl; });
    t1.join();
    return 0;
}
```

#### Using a Functor (Callable Object)
```cpp
#include <iostream>
#include <thread>

class Task
{
public:
    void operator()()
    {
        std::cout << "Thread is running" << std::endl;
    }
};

int main()
{
    std::thread t1(Task());
    t1.join();
    return 0;
}
```

### 2. Joining and Detaching Threads
- **`join()`**: Blocks the calling thread until the created thread finishes execution.
- **`detach()`**: Separates the thread from the main thread, allowing it to run independently.

```cpp
std::thread t(task);
t.join();  // Ensures thread completes execution
// OR
// t.detach();  // Runs independently, may cause issues if main() exits first
```

### 3. Thread Synchronization
Since multiple threads share resources, synchronization is required to avoid race conditions.

#### Mutex (Mutual Exclusion)
A `std::mutex` prevents multiple threads from modifying a shared resource simultaneously.

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void task(int id)
{
    mtx.lock();
    std::cout << "Thread " << id << " is executing" << std::endl;
    mtx.unlock();
}

int main()
{
    std::thread t1(task, 1);
    std::thread t2(task, 2);
    
    t1.join();
    t2.join();
    return 0;
}
```

#### `std::lock_guard` and `std::unique_lock`
Instead of manually locking and unlocking, `std::lock_guard` and `std::unique_lock` automatically handle mutex locking and unlocking.

```cpp
void task(int id)
{
    std::lock_guard<std::mutex> guard(mtx);
    std::cout << "Thread " << id << " is executing" << std::endl;
}
```

### 4. Condition Variables
Condition variables allow threads to wait for a condition to be met before proceeding.

```cpp
#include <iostream>
#include <thread>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });
    std::cout << "Worker thread proceeding" << std::endl;
}

int main()
{
    std::thread t(worker);
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    t.join();
    return 0;
}
```

### 5. Thread Pooling
A thread pool manages a set of reusable threads to handle multiple tasks efficiently.

```cpp
#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

public:
    ThreadPool(size_t threads) : stop(false)
    {
        for (size_t i = 0; i < threads; ++i)
        {
            workers.emplace_back([this]
            {
                while (true)
                {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);
                        this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                        if (this->stop && this->tasks.empty())
                            return;
                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    void enqueue(std::function<void()> task)
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace(task);
        }
        condition.notify_one();
    }

    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker : workers)
            worker.join();
    }
};

int main()
{
    ThreadPool pool(4);
    pool.enqueue([] { std::cout << "Task executed" << std::endl; });
    return 0;
}
```

## Summary
- **Threads** allow parallel execution of tasks.
- **`std::thread`** is used to create and manage threads.
- **Synchronization mechanisms** like `std::mutex`, `std::lock_guard`, and `std::condition_variable` prevent data races.
- **Thread pools** help in managing multiple threads efficiently.

Multithreading improves program efficiency but requires careful synchronization to avoid race conditions and deadlocks. Understanding and using the right tools ensures safe and effective multithreading in C++ applications.


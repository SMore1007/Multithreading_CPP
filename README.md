# Multithreading in C++

Multithreading is the ability of a program to run multiple threads concurrently, allowing for parallel execution of tasks. In C++, multithreading is supported using the <thread> library, which enables efficient CPU utilization and improved performance in applications.
1. What is a Thread?

A thread is the smallest unit of execution within a process. A program can have multiple threads running independently but sharing the same memory space.

2. Why Use Multithreading?

    Performance Boost: Runs tasks in parallel, utilizing multi-core processors.

    Responsiveness: Keeps applications responsive (e.g., GUI apps).

    Efficient Resource Use: Prevents blocking operations from halting execution.

    Concurrency: Handles multiple tasks simultaneously, such as network requests and computations.

    Ex: the browser has multiple tabs that can be different threads

3. Way to create the threads
    1. Function pointer
    2. lambda function
    3. Functors
    4. Member Functions
    5. Static Member Functions
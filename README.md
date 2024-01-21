# Multithreading Tests

A collection of C++ programs that were written to test out various multithreading concepts in C++.

The list includes:
1) `test_num_threads.cpp` creates a certain number of threads until an exception has occured. It also invokes the `std::thread::hardware_concurrency()` which is a method of the standard thread library that calculates, from the system's current resources, the optimal number of threads that should be used.
2) `lock_guard.cpp` which is where I try out the use of a `lock_guard` in C++. It locks the mutex when created, releases it when the guard is out of scope. It also keeps the mutex locked even if the thread has called another function which results in an exception.
3) `parallel_fib.cpp` which was inspired by the relevant section from the book "Introduction to Algorithms". However, upon trying their method in replit.com with bigger numbers in the Fibonacci sequence, an exception was thrown indicating that there were not enough cores to process the number. An alternative I am currently seeking out is the use of a thread pool, in which a limited number of threads may be used to run several Fibonacci calculations in parallel. 
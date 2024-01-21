#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // to protect critical section

void print_even(int x) {
    if(x % 2 == 0) {
        std::cout << x << " is even\n";
    }
    else {
        throw(std::logic_error("not even"));
    }       
}

void print_thread(int id) {
    try {
        std::lock_guard<std::mutex> lck(mtx); // locks the mutex, and keeps it locked
        // RAII (Resource Acquisition Is Initlization)?
        print_even(id);
    }  
    catch(std::logic_error&) {
        std::cout << "[Exception Caught]\n";
    }
}

int main() {
    std::thread threads[10];
    for(int i=0; i<10; i++) {
        threads[i] = std::thread(print_thread, i+1);
    }
    for(auto& th: threads) {
        th.join();
    }
    return 0;
}
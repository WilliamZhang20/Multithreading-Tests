#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void thread_function() {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main() {
	std::vector<std::thread> threads;
    int i=0;
    int limit = 100;
	try {
		while(i<limit) {
			threads.emplace_back(thread_function);
            i++;
		}
	} catch(const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Threads created: " << threads.size() << std::endl;
	for(auto& t: threads) {
		t.join();
	}
    std::cout << "We're done\n";
    std::cout << "Actual limit of CONCURRENT threads: " << std::thread::hardware_concurrency() << std::endl;
	return 0;
}
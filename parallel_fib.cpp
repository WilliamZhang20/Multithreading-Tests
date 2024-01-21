#include <iostream>
#include <thread>
#define ll long long

void parallel_fib(int n, int& number) {
	try {
		if (n <= 1) {
			number = n;
			return;
		}

		int x = 0, y = 0;

		std::thread t1(parallel_fib, n - 1, std::ref(x));
		std::thread t2(parallel_fib, n - 2, std::ref(y));

		t1.join();
		t2.join();

		number = x + y;
	} catch (const std::exception& e) {
		// Often too many threads that memory is busted
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main() {
	int n = 0;
	std::cin >> n;

	int result = 0;
	parallel_fib(n, result);

	std::cout << result << std::endl;

	return 0;
}

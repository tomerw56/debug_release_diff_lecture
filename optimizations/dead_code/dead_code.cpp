#include <iostream>
#include <chrono>

int main() {
    bool flag = false;
    int result = 0;

    // Unreachable code (dead code elimination)
    if (flag) {
        result = 42;  // This line will never be executed
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        result += i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Result: " << result << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}

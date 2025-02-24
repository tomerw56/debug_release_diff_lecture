#include <iostream>
#include <chrono>

int main() {
    const int multiplier = 100;
    int result = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000000; ++i) {
        result += multiplier * 10;  // Constant propagation should simplify this
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Result: " << result << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}

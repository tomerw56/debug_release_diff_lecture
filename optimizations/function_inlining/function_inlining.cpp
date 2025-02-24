#include <iostream>
#include <chrono>

inline double square(double x) {
    return x * x;
}

int main() {
    const int size = 100000000;
    double sum = 0.0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        sum += square(3.14);  // Function call
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}

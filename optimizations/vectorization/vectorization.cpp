#include <iostream>
#include <chrono>

int main() {
    const int size = 1000000;
    double data1[size], data2[size], result[size];

    // Initialize arrays
    for (int i = 0; i < size; ++i) {
        data1[i] = 1.0;
        data2[i] = 2.0;
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        result[i] = data1[i] + data2[i];  // Simple element-wise addition
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}

#include <iostream>
#include <chrono>

int main() {
    const int size = 100000000;
    double sum = 0.0;
    double data[size];

    // Initialize array with some values
    for (int i = 0; i < size; ++i) {
        data[i] = 1.0;
    }

    // Timed summing loop
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i += 4) {
        sum += data[i] + data[i+1] + data[i+2] + data[i+3];
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time: " << duration.count() << " ms" << std::endl;
    return 0;
}

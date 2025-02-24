#include <iostream>
#include <iomanip>  // For std::setprecision
#include <chrono>

int main() {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    double result1 = 0.0;
    double result2 = 0.0;
    const double smallValue = 1e-16;
    const int iterations = 1000000000;  // 1 billion iterations

    // Perform accumulation of small value in a simple loop
    for (int i = 0; i < iterations; ++i) {
        result1 += smallValue;  // Accumulate normally
    }

    // Perform accumulation with small reordering of operations
    for (int i = 0; i < iterations; ++i) {
        result2 += smallValue;  // Accumulate with same value but potentially optimized in release mode
    }

    // Output results with maximum precision
    std::cout << "Result1: " << std::setprecision(60) << result1 << std::endl;
    std::cout << "Result2: " << std::setprecision(60) << result2 << std::endl;
    // End time
    auto end = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<microseconds>(end - start);  // In microseconds
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}

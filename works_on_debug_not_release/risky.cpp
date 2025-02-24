#include <iostream>

void riskyFunction() {
    int x;  // Uninitialized variable
    if (x == 0) {  // Conditional check on uninitialized memory
        std::cout << "This won't be printed." << std::endl;
    }
}

int main() {
    riskyFunction();
    return 0;
}

//release cl /Zi /EHsc /O2 .\risky.cpp
//debug cl /Zi /EHsc /Od .\risky.cpp
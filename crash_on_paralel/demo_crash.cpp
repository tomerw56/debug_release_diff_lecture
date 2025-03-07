#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <cstdlib>
#include <ctime>

// Shared data
std::queue<int> dataQueue;
std::mutex mtx;
std::condition_variable cv;

// Producer function
void producer(int id) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx);
        int data = rand() % 100;
        dataQueue.push(data);
        std::cout << "Producer " << id << " produced " << data << std::endl;
        cv.notify_all();
    }
}

// Consumer function
void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !dataQueue.empty(); });

        int data = dataQueue.front();
        dataQueue.pop();
        std::cout << "Consumer " << id << " consumed " << data << std::endl;

        // Simulate a crash in one of the consumers
        if (id == 2) { // Let's crash consumer 2
            std::cout << "Consumer " << id << " crashed!" << std::endl;
            std::terminate();  // This will cause a crash
        }

        // Simulate processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    srand(time(0));

    // Create threads for producers and consumers
    std::vector<std::thread> threads;

    // Start producer threads
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(producer, i));
    }

    // Start consumer threads
    for (int i = 0; i < 3; ++i) {
        threads.push_back(std::thread(consumer, i));
    }

    // Join all threads
    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point start;
public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cerr << "\n-----------------------------" << std::endl;
        std::cerr << "Tiempo de ejecucion: " << duration.count() << " ms" << std::endl;
        std::cerr << "-----------------------------" << std::endl;
    }
};

#ifndef ONLINE_JUDGE
    #define START_TIMER Timer _timer
#else
    #define START_TIMER
#endif

#endif

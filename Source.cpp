#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <random>

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count();
    }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};
using namespace std;

// Imports from other files
unsigned long long sumAllDivisors1(unsigned long long n);
unsigned long long sumAllDivisors2(unsigned long long n);

int main() {
    /* Seed */
    std::random_device rd;

    /* Random number generator */
    std::default_random_engine generator(rd());

    /* Distribution on which to apply the generator */
    std::uniform_int_distribution<unsigned long long> distribution(0, 0xFFFFFFFFFFFFFFFF);

    for (int i = 0; i < 10; i++) {
        unsigned long long n = distribution(generator);
        Timer tmr;

        tmr.reset();
        unsigned long long res1 = sumAllDivisors1(n);
        double time1 = tmr.elapsed();

        tmr.reset();
        unsigned long long res2 = sumAllDivisors2(n);
        double time2 = tmr.elapsed();
        
        cout << n << endl;
        cout << res1 << " " << time1 << endl;
        cout << res2 << " " << time2 << endl;
        cout << "--------------------" << endl;
    }
    return 0;
}
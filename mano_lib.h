#include <bits/stdc++.h>
#include <chrono>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::floor;
using std::ifstream;
using std::istringstream;
using std::left;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;
using std::ws;
using namespace std::literals::chrono_literals;
using std::ofstream;

struct Stud
{
    string var, pav;
    vector<int> nd;
    int egz;
};

struct Stud1
{
    string var, pav;
    int *nd{nullptr};
    int n = 0;
    int egz;
};

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const
    {
        return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
    }
};

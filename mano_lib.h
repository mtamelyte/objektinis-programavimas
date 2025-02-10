#include <bits/stdc++.h>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::sort;
using std::fixed;
using std::setprecision;
using std::floor;
struct Stud{
    string var, pav;
    vector <int> nd;
    int egz;
};

struct Stud1{
    string var, pav;
    int* nd{nullptr};
    int n=0;
    int egz;
};
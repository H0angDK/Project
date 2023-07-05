#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
int recursion(int a, int d, int n, int& count) {
    ++count;
    if (n == 1)
        return a;
    else
        return recursion(a + d, d, n - 1, count);
}

int cycle(int a, int d, int n, int& count) {
    int term = a;
    for (int i = 2; i <= n; ++i) {
        ++count;
        term += d;
    }
    return term;
}
int recursion1(int a, int d, int n) {
    if (n == 1)
        return a;
    else
        return recursion1(a + d, d, n - 1);
}

int cycle1(int a, int d, int n) {
    int term = a;
    for (int i = 2; i <= n; ++i) {
        term += d;
    }
    return term;
}
void task02() {
    int a = -10, d = 1, n1 = 1000;
    cout << "starting work\n";
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1e+7; i++) {
        recursion1(a, d, n1);
    }
    auto finish = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(finish - start);
    cout << "recursion: " << duration.count() << " seconds\n";
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 1e+7; i++) {
        cycle1(a, d, n1);
    }
    auto finish1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::seconds>(finish1 - start1);
    cout << "cycle: " << duration1.count() << " seconds\n";
    cout << "finishing work\n";
    int a1, k, n, countRecursive = 0, countCycle = 0;
    cout << "First element\n";
    cin >> a1;
    cout << "difference\n";
    cin >> k;
    cout << "member\n";
    cin >> n;
    cout << "recursion\n" << "result:\t" << recursion(a1, k, n, countRecursive) << "\nthe number of iterations is " << countRecursive << endl;
    cout << "cycle\n" << "result:\t" << cycle(a1, k, n, countCycle) << "\nthe number of iterations is " << countCycle << endl;
}
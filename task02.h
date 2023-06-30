#pragma once
#include <iostream>
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

void task02() {
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
#pragma once
#include <iostream>
using namespace std;
int recursion(int a, int k, int n) {
    if (n == 1) return a;
    return recursion(a, k, n - 1) + k;
}
int cycle(int a, int k, int n) {
    for (int i = 1; i < n; i++)
        a += k;
    return a;
}
void task02()
{
    int a1, k, n;
    cout << "First element\n";
    cin >> a1;
    cout << "difference\n";
    cin >> k;
    cout << "member\n";
    cin >> n;
    cout << recursion(a1, k, n) << endl;
    cout << cycle(a1, k, n) << endl;
}
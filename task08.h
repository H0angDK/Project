#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "utils.h"
using namespace std;
int findDet(int** a, int n) { 
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        int d = 0;
        for (int k = 0; k < n; k++) {
            int** m = new int* [n - 1];
            for (int i = 0; i < n - 1; i++) {
                m[i] = new int[n - 1];
            }
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
            deleteArray(m, n - 1);
        }
        return d;
    }
}
double** convect(int** arr, int n, int m) {
    double** a = new double* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double[m];
        for (int j = 0; j < m; ++j)
            a[i][j] = arr[i][j];
    }
    return a;
}

void task08(string path) {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;
    int** tmp;
    while (true) {
        tmp = gen2Darr(n, 10, -10);
        if (findDet(tmp, n) != 0)
            break;
    }
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[n + 1];
        for (int j = 0; j < n; ++j) {
            arr[i][j] = tmp[i][j];
            arr[i][n] = fillArr(10,-10);
        }
    }
    write2DArr(arr, n, n + 1, path);
    deleteArray(tmp, n);
    deleteArray(arr, n);
    double** a = convect(read2DArr(n, n + 1, path), n, n + 1);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "utils.h"
using namespace std;
void print(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void deleteOne(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int val = 0;
			if (arr[i][j] == 1) {
				for (int p = 0; p < n; ++p) {
					for (int q = 0; q < n; ++q) {
						if (arr[p][q] != 1) {
							int len = abs(i - p) + abs(j - q);
						}
					}
				}
			}
		}
	}
}
void task07(string path) {
	srand(time(NULL));
	int n;
	cout << "enter length\n";
	cin >> n;
	cout << n;
	int** arr = gen2Darr(n, 1000000, 1);
	write2DArr(arr, n, n, path);
	deleteArray(arr, n);
	int** fileArr = read2DArr(n, n, path);
	print(fileArr, n);
}
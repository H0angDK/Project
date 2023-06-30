#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include "utils.h"
const int MAX = 401;//|200-0|+|200-0|<401
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
			int val = 0, max = MAX;
			if (arr[i][j] == 1) {
				for (int p = 0; p < n; ++p) {
					for (int q = 0; q < n; ++q) {
						if (arr[p][q] != 1) {
							int len = abs(i - p) + abs(j - q);
							if(len < max) {
								max = len;
								val = arr[p][q];
							}
						}
					}
				}
				arr[i][j] = val;
			}
		}
	}
}
void check(int** arr, int n) {
	for (int i = 0; i < rand() % n * n + 1; i++) {
		arr[rand() % n][rand() % n] = 1;
	}
}
void task07(string path) {
	srand(time(NULL));
	int n;
	cout << "enter length\n";
	cin >> n;
	if (n < 1||n >= 201){
		cout << "length is < 1 or > 200\n";
		return;
	}
	int** arr = gen2Darr(n, 1000000, 1);
	check(arr, n);
	write2DArr(arr, n, n, path);
	deleteArray(arr, n);
	int** fileArr = read2DArr(n, n, path);
	cout << "old\n";
	print(fileArr, n);
	deleteOne(fileArr, n);
	cout << "new\n";
	print(fileArr, n);
	deleteArray(fileArr, n);
}
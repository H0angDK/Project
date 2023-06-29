#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;
int fillArr() {
	return rand() % 1000000 + 1;
}
int** gen2Darr(int n) {
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = fillArr();
		}
	}
	return arr;
}
void deleteArray(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr; 
}
void print(int** arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
void task07(string path) {
	srand(time(NULL));
	int n;
	cout << "enter length\n";
	cin >> n;
	cout << n;
	int** arr = gen2Darr(n);
	write2DArr(arr, n, path);
	deleteArray(arr, n);
	int** fileArr = read2DArr(n, path);
	print(fileArr, n);
}
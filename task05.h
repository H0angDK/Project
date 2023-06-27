#pragma once
#include <string> 
#include <iostream>
#include "utils.h"
using namespace std;
bool isFactor(int num,int &k) {
	if (num < 0) return false;
	if (num == 0) {
		k = 1;
		return true;
	}
	int i = 1;
	while (true) {
		if (num % i == 0) {
			num /= i;
			i++;
		}
		else {
			break;
		}
	}
	k = i-1;
	if (num == 1) { return true; }
	else return false;
}
void task05(string path) {
	int size;
	int* arr = readArray(path, size);
	for (int i = 0; i < size; i++) {
		int k = 0;
		if (isFactor(arr[i], k)) {
			cout << arr[i] << "=" << k << "!\n";
		}
	}
	delete[] arr;
}
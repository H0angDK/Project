#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int* readArray(string path,int &size) {
	ifstream fin(path);
	if (fin.is_open()) {
		int num, i = 0;
		while (fin >> num) {
			i++;
		}
		size = i;
		fin.close();
		int* arr = new int[size];
		i=0;
		fin.open(path);
		while (fin >> num) {
			arr[i] = num;
			i++;
		}
		return arr;
	}
	else {
		return 0;
	}
}
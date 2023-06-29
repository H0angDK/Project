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
		cout << "file not open\n";
		return NULL;
	}
}
void write2DArr(int** arr, int n, string path) {
	ofstream fout(path);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fout << arr[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}
int** read2DArr(int n, string path) {
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) arr[i] = new int[n];
	ifstream fin(path);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fin >> arr[i][j];
		}
	}
	fin.close();
	return arr;
}

string readText(string path) {
	ifstream fin(path);
	string line, text;
	if (fin.is_open())
	{
		while (getline(fin, line)) {
			text += line + "\n";
		}
	}else{
		cout << "file is noy open\n";
	}
	fin.close();
	return text;
}
void writeText(string path, string text) {
	ofstream fout(path);
	if (fout.is_open()) {
		fout << text;
		string a = readText(path);
		cout <<"text is write successful\n";
	}
	else {
		cout << "file not open\n";
	}
}
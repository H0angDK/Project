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
		cout << "file is not open\n";
		return NULL;
	}
}
void writeSolution(string path, int n, double* x) {
	ofstream fout(path);
	if (!fout.is_open()) {
		cout << "file is not open\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		fout << "x[" << i << "]=" << x[i] << endl;
	}
	fout.close();
}
void write2DArr(int** arr, int n, int m, string path) {
	ofstream fout(path);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fout << arr[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}

int** read2DArr(int n, int m, string path) {
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	ifstream fin(path);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
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
		cout << "file is not open\n";
	}
	fin.close();
	return text;
}
void writeText(string path, string text) {
	ofstream fout(path);
	if (fout.is_open()) {
		fout << text;
		string a = readText(path);
	}
	else {
		cout << "file not open\n";
	}
}
struct Last5Games
{
	int goal;
};
struct FootballPlayer{
	string name;
	string position;
	int age;
	int games;
	int goals;
	Last5Games lasts;
};
void writeBin(string path, FootballPlayer club[],int n) {
	ofstream fout(path, ios::binary);
	if (fout.is_open()) {
		fout.write(reinterpret_cast<const char*>(club), sizeof(FootballPlayer) * n);
		cout << "text is write successful\n";
		fout.close();
	}
	else
	{
		cout << "Error opening file" << endl;
		return;
	}
}
void readBin(string path,FootballPlayer club[],int n) {
	ifstream fin(path,ios::binary);
	if (fin.is_open()) {
		fin.read(reinterpret_cast<char*>(club), sizeof(FootballPlayer) * n);
		fin.close();
	}
	else {
		cout << "Error opening file" << endl;
		return;
	}
}

int fillArr(int max, int min) {
	return rand() % (max - min + 1) + min;
}
int** gen2Darr(int n, int max, int min) {
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = fillArr(max, min);
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
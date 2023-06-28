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
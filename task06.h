#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
using namespace std;
string deleteWord(string text, int len) {
    string word, result;
    const string signs = ".,?!:\n; ";
    for (int i = 0; i < text.length(); i++) {
        bool isSign = false;
        for (int j = 0; j < signs.length(); ++j) {
            if (text[i] == signs[j]) {
                isSign = true;
                break;
            }
        }
        if (isSign) {
            if (word.length() != len) {
                result += word;
                result += text[i];
            }
            isSign = false;
            word = "";
        }
        else {
            word += text[i];
        }
    }
    result += word;
    return result;
}

void task06(string path,string pathRes){
	string text = readText(path);
	cout << "text:\n" << text << endl;
	int len;
	cout << "Enter length\n";
	cin >> len;
    string res = deleteWord(text, len);
    writeText(pathRes, res);
}


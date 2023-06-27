#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void task01(string path) {
    int num = 10, stop = 0;
    string command, end;
    ofstream outputFile(path);
    while (true) {
        cout << num << endl;
        getline(cin, command);
        //cout<<command<<endl;
        if (command != ":2" && command != "-1") {
            cout << "invalid command\n";
            continue;
        }
        if (num % 2 == 1 && command == ":2") {
            cout << "invalid command\n";
            continue;
        }
        if (command == "-1") {
            num -= 1;
            if (outputFile.is_open()) {
                outputFile << num << endl;
            }
            else {
                cout << "Unable to open file\n";
                break;
            }
        }
        else if (command == ":2") {
            num /= 2;
            if (outputFile.is_open()) {
                outputFile << num << endl;
            }
            else {
                cout << "Unable to open file\n";
                break;
            }
        }
        while (true) {
            cout << "continue?\t[y/n]\n";
            getline(cin, end);
            if (end != "y" && end != "n") {
                cout << "invalid command\n";
                continue;
            }
            if (end == "n") {
                stop = 1;
                break;
            }
            if (end == "y") {
                stop = 0;
                break;
            }
        }
        if (stop || num <= 0) {
            cout << "work complete\n";
            break;
        }
    }
    outputFile.close();
}
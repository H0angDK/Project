#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
long double calc(double a, double b, double x, double eps) {
	const double y = 0.57721566;
	long double start = 1.0;
	long double element = 1.0;
	int i = 0;
	while (abs(element) > eps){
		element *= (a + i) * (b + i) * powl(x, i) / (i + 1) / (y + i);
		start += element;
		cout << start << endl;
		if (i == 1000) break;
		i++;
	}
	return start;
}
void task03() {
	double a,b,x,eps=1e-3;
	cout << "Enter a\n";
	cin >> a;
	cout << "Enter b\n";
	cin >> b;
	cout << "Enter x\n";
	cin >> x;
	cout << "Enter eps\n";
	cin >> eps;
	cout <<"the result is " << calc(a, b, x,eps);
	
}
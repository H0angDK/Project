#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double calc(double a, double b, double x, double eps) {
	const double y = 0.57721566;
	double start = 1.0;
	double element = 1.0;
	int i = 0;
	while (fabs(element) > eps) {
		element *= (a + i) * (b + i) * x / ((i + 1) * (y + i));
		start += element;
		i++;
	}
	return start;
}

void task03() {
	double a, b, x, eps = 1e-10;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter x: ";
	cin >> x;
	cout << "F(" << a << ", " << b << ", " << x << ") = " << calc(a, b, x, eps) << endl;
}
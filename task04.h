#pragma once
//2 sign 
#include <cmath>
long long factor(long long i) {
	if (i == 0 || i == 1) return 1;
	return i * factor(i - 1);
}
long double partSin(long double x) {
	long double result = 0;
	for (int i = 0; i < 35; i++) {
		result += powl(-1, i) * powl(x, 2.0 * i + 1) / ((2.0 * i + 1) * factor(x * i + 1));
	}
	return result;
}

void task0401() {
	double start = 0.1;
	double end = 1.0;
	for (double i = 0.1; i <= end + 0.000001; i += 0.05) {
		cout << "Si" << "(" << i << ") = " << partSin(i) << endl;
	}
}

double partSin2(double x, double eps) {
	double sum = x;
	double term = x;
	int n = 1;
	while (abs(term) > eps) {
		term *= -x * x / ((2 * n + 1) * (2 * n));
		sum += term / (2 * n + 1);
		n++;
	}
	return sum;
}

void task0402() {
	double start = 0.1;
	double end = 1.0;
	double step = 0.05;
	double eps = 1e-5;
	for (double x = start; x <= end + 0.0001; x += step) {
		cout << "Si(" << x << ") = " << partSin2(x, eps) << endl;
	}
}


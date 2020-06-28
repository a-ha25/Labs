#include <iostream>
#include <math.h>
using namespace std;
double fun(double x) {
	return pow(x, 2) - 10 * pow(sin(x), 2) + 2;
}

double Method(double x0, double x1, double eps) {
	double y0, y1, x2, accuracy;
	y0 = fun(x0);	   y1 = fun(x1);
	do {
		x2 = x1 - y1 * (x1 - x0) / (y1 - y0);//x-f(x)/f'
		accuracy = fabs(x1 - x2);
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = fun(x2);
	} while (accuracy > eps);
	return x2;
}

int main() {
	double a = -1, b = 3;
	double h = 0.1, eps = 0.0000001;

	double answer[3];
	int index = 0;
	for (double x = a; x < b; x += h) {
		if (fun(x) * fun(x + h) < 0) {
			answer[index] = Method(x, x + h, eps);
			index++;
		}
	}
	for (double x : answer) {
		cout << x << " - Root\t" << fun(x) << " - Value\t" << endl;
	}
}


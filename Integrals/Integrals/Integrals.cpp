#define _USE_MATH_DEFINES
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include<Windows.h>
#include<iostream>

double fun(double x) {
	return sin(x);
}

using namespace std;
int main()
{
	system("color 02");
	setlocale(LC_ALL, "RUS");
	double eps,a,b,S0,S1,S2,I1,I2,h;
	int n;
	cout << "введите погрешность: 10^-5"<<endl;
	//cin >> eps;
	eps = pow(10, -5);
	cout << "введите левую границу: 0";
	//cin >> a;
	a = 0;
	cout << "введите правую границу: "<< M_PI << endl;
	b = M_PI;
	//cin >> b;
	cout << "введите четное n ";
	cin >> n;
	S0 = fun(a) + fun(b);
	S1 = 0;
	h = (b - a) / n;
	for (int i = 1; i < n / 2; i++)
		S1 += fun(a + (2 * i - 1) * h);
	S2 = 0;
	for (int i = 0; i < n / 2; i++)
		S2 += fun(a + (2 * i) * h);
	I1 = (b - a) / (3 * n) * (S0 + 4 * S1 + 2 * S2);
	n = 2 * n;
	h = (b - a) / n;
	S2 = S1 + S2;
	S1 = 0;
	for (int i = 1; i < n / 2; i++)
		S1 += fun(a + (2 * i - 1) * h);
	I2 = (b - a) / (3 * n) * (S0 + 4 * S1 + 2 * S2);
	if (fabs(I2 - I1) <= eps*15/16)
		cout <<endl <<I2;
	else
	{		
		do {
			I1 = I2;
			n = 2 * n;
			h = (b - a) / n;
			S2 = S1 + S2;
			S1 = 0;
			for (int i = 1; i < n / 2; i++)
				S1 += fun(a + (2 * i - 1) * h);
			I2 = (b - a) / (3 * n) * (S0 + 4 * S1 + 2 * S2);
		} while (fabs(I2 - I1) >= eps*15/16);
	}
	cout << endl << I2;
	
	getchar(); getchar();
	return 0;
}
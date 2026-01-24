/*
   This program calculates the area of a triangle using Heron's formula.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a, b, c, d, e, f, g;
	cout << "Enter the lengths of the three sides of the triangle: ";
	cin >> a >> b >> c;
	d = a + b + c;
	e = d / 2;
	f = e * (e - a) * (e - b) * (e - c);
	g = sqrt(f);
	cout << "The square of the triangle is " << g << endl;
}

//// Homework 1 - Binary.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//#include <iostream>
//#include "Binary.h"
//
//using namespace std;
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	Binary *test1 = new Binary(1);
//	Binary test2(1);
//	Binary test3;
//
//	test3 += test2;
//	test3 -= test2;
//	test3 -= test2;
//	test3 -= test2;
//
//	cout << test3 << endl;
//	cout << test3.toInt() << endl;
//
//	return 0;
//}
//

// HW1.cpp
// This is a simple driver to perform basic testing on student code for CSS 343 HW1.
// If your code compiles with this driver, it should compile with the (much more extensive)
// driver that I will be testing with.
// Author: Clark Olson

#include "Binary.h"
#include <iostream>
using namespace std;

// main: driver for HW1
// preconditions: 	None (note that the preconditions are run-time issues, not compile-time issues)
// postconditions: 	Outputs results to the console window and returns 0.
//					Should NOT crash if Binary class is correct.
int main()
{
	Binary a, b(42), c(b), d = -13, x, y = x + 1;

	cout << "Enter integer to be converted to binary:  ";
	cin >> a;
	cout << "The binary representation of this number is: " << endl;
	cout << a << endl;
	cout << "The 4th bit (four bits away from bit 0) is: " << endl;
	cout << a.getBit(4) << endl << endl;

	cout << "Compute c = a + b" << endl;
	c = a + b;
	cout << "c = " << c << endl;
	cout << "Compute d = a + b - c" << endl;
	d = a + b - c;
	cout << "d = " << d << endl << endl;

	cout << "Does a == c? " << endl;
	cout << ((a == c) ? "a == c" : "a != c") << endl << endl;

	cout << "Test assignment operators" << endl;
	x = c = d = d;    
	y += a -= b += b;
	cout << "x = " << x << "    y = " << y << endl << endl;

	a.setBit(-1);			// handle bad input
	a.setBit(3);			// set 3rd bit (three over from bit zero)
	a.setBit(1000);			// set 1000th bit; handle as desired, but don't crash
	a.clearBit(3);			// clear 3rd bit
	a.clearBit(10000);		// clear 10000th bit
	a.toggleBit(3);			// toggle 3rd bit

	return 0;
}

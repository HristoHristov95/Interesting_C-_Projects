#include<iostream>
using namespace std;
class Point {
	int a;
public:
	Point(int = 1);
	void setA(int);
};
Point::Point(int b) : a(b) {}
void Point::setA(int a) { this->a = a; }
class Square {
	int b;
	Point object;
public:
	Square(int = 1, int = 1);
	void setAB(int, int);
};
Square::Square(int a, int b) : b(a) { object.setA(b); }
void Square::setAB(int a, int b) { this->b = a; object.setA(b); }
class Cube {
	int c;
	Square object;
public:
	Cube(int = 1, int = 1, int = 1);
};
Cube::Cube(int a, int b, int c) : c(a) { object.setAB(b, c); }

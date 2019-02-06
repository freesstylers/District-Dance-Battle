#include "Vector2D.h"
#include <math.h>
using namespace std;

Vector2D::Vector2D() : x(), y() {}
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}
double Vector2D::CompX() const { return x; }
double Vector2D::CompY() const { return y; }
void Vector2D::normalize() {
	double mag = sqrt(pow(x, 2) + pow(y, 2));
	if (mag > 0.0) {
		x = x / mag;
		y = y / mag;
	}
}
Vector2D Vector2D::operator+(const Vector2D& v) const
{
	Vector2D r;
	r.x = x + v.x;
	r.y = y + v.y;
	return r;
}
Vector2D Vector2D::operator-(const Vector2D& v) const
{
	Vector2D r;
	r.x = x - v.x;
	r.y = y - v.y;
	return r;
}
Vector2D Vector2D::operator*(double d)const
{
	Vector2D r;
	r.x = x * d;
	r.y = y * d;
	return r;
}
double Vector2D::operator*(const Vector2D& v) const {
	double d = x * v.x + y * v.y;
	return d;
}
Vector2D::~Vector2D()
{
}
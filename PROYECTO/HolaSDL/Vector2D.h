#pragma once
#include "checkML.h"
class Vector2D
{
private:
	double x;
	double y;
public:
	Vector2D();
	Vector2D(double x, double y);
	~Vector2D();
	double CompX() const;
	double CompY()const;
	void normalize();
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator-(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& d)const;


};

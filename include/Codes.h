#include "iostream"

#pragma once

namespace codes {

struct ExitStatus {
public:
	static const int StatusNoError = 0;
	static const int Success = 0;
	static const int StatusAppInitFailed = 1;
};

struct Colors {
	static const bool Black = 1;
	static const bool White = 0;
};

class CellID
{
private:
	int X;
	int Y;
public:
	CellID(const int _x, const int _y)
	{
		// Sets the variables to be able to compare them on setY() and setX()
		X=_x;
		Y=_y;
		setY(_y);
		setX(_x);
	}
	CellID& operator=(CellID other)
    {
        std::swap(X, other.X);
        std::swap(Y, other.Y);
        return *this;
    }
	int y() {return Y;}
	int x() {return X;}
	void setX(const int _x)
	{
		if (_x%2 != Y%2 or _x<0 or _x>6)
		{
			throw "Invalid CellID";	
		} else {
			X = _x;
		}
	}
	void setY(const int _y)
	{
		if (X%2 != _y%2 or _y<0 or _y>6)
		{
			throw "Invalid CellID";	
		} else {
			Y = _y;
		}
	}
};
}

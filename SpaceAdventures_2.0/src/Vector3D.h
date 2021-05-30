#pragma once
#include <iostream>
//IF THERE IS AN ERROR HERE I RETURN RVALUES INSTEAD OF LVALUES,....REWATCH #9 AND COPY HIS CODE

template <typename TypeA, typename TypeB, typename TypeC>
class Vector3D
{
public:

	Vector3D() :x(0), y(0) {}

	Vector3D(TypeA x, TypeB y, TypeC z) :x(x), y(y), z(z) {}
	//Vector3D(TypeA&& x, TypeB&& y, TypeC&& z) :x(x), y(y), z(z) {}

	inline TypeA GetX() const { return x; }
	inline void SetX(TypeA xVal) { x = xVal; }

	inline TypeB GetY() const { return y; }
	inline void SetY(TypeB yVal) { y = yVal; }

	inline TypeC GetZ() const { return z; }
	inline void SetZ(TypeC zVal) { z = zVal; }


	TypeA x;
	TypeB y;
	TypeC z;	
private:

	

	/*Vector3D& Add(const Vector3D& vec);
	Vector3D& Subtract(const Vector3D& vec);
	Vector3D& Multiply(const Vector3D& vec);
	Vector3D& Divide(const Vector3D& vec);

	friend Vector3D& operator+(Vector3D& v1, const Vector3D& v2);
	friend Vector3D& operator-(Vector3D& v1, const Vector3D& v2);
	friend Vector3D& operator*(Vector3D& v1, const Vector3D& v2);
	friend Vector3D& operator/(Vector3D& v1, const Vector3D& v2);

	Vector3D& operator+=(const Vector3D& vec);
	Vector3D& operator-=(const Vector3D& vec);
	Vector3D& operator*=(const Vector3D& vec);
	Vector3D& operator/=(const Vector3D& vec);

	Vector3D& operator*(const int& i);
	Vector3D& Zero();

	friend std::ostream& operator<<(std::ostream& stream, const Vector3D& vec);*/
};

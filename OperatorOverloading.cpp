#include <iostream>

class Vector3
{
private:
    double _x;
    double _y;
    double _z;
public:
    Vector3(double x = 0.0, double y = 0.0, double z = 0.0) 
        : _x{ x }, _y{ y }, _z{ z }
    {

    }

    friend std::ostream& operator<< (std::ostream& out, const Vector3& point);
    friend std::istream& operator>> (std::istream& in, Vector3& point);
    friend Vector3 operator* (const Vector3& vector, const double& num);
    friend Vector3 operator- (const Vector3& first, const Vector3& second);
};

std::ostream& operator<<(std::ostream& out, const Vector3& point)
{
    out << '(' << point._x << ", " << point._y << ", " << point._z << ')';
    return out;
}

std::istream& operator>>(std::istream& in, Vector3& point)
{
    in >> point._x;
    in >> point._y;
    in >> point._z;
    return in;
}

Vector3 operator*(const Vector3& vector, const double& num)
{
    return Vector3(vector._x * num, vector._y * num, vector._z * num);
}

Vector3 operator-(const Vector3& first, const Vector3& second)
{
    return Vector3(first._x - second._x, first._y - second._y, first._z - second._z);
}

int main()
{
    Vector3 vector;
    std::cin >> vector;
    std::cout << vector;

    std::cout << vector * 3.0;

    std::cout << vector - vector;
}

#include <iostream>
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D(double _x, double _y) : x(_x), y(_y) {}
    Point2D() : x(0), y(0) {}
    friend Point2D operator-(Point2D a);
    double getX() { return x; }
    double getY() { return y; }
    void print() { cout << "(" << getX() << ", " << getY() << ")" << endl; }
    Point2D operator+(Point2D b)
    {
        return Point2D(x + b.x, y + b.y);
    }

    Point2D operator-(Point2D b)
    {
        return Point2D(x - b.x, y - b.y);
    }
};

int main()
{
    Point2D p(1, 3);
    Point2D p2(3, 4);

    Point2D p3 = p + p2;
    Point2D p4 = p - p2;

    p3.print();
    p4.print();
}
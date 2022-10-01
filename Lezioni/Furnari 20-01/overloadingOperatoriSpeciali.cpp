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
    friend ostream &operator<<(ostream &, Point2D);
    friend Point2D operator++(Point2D &, int);
};

ostream &operator<<(ostream &s, Point2D p)
{
    s << "(" << p.x << ", " << p.y << ")" << endl;
    return s;
}

Point2D operator++(Point2D &obj, int)
{
    Point2D aux = obj;
    obj.x++;
    return aux;
}

int main()
{
    Point2D p(1, 3);
    Point2D p2(3, 4);
    p++;
    cout << p;
}
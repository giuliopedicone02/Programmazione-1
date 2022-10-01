#include <iostream>
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D(double _x, double _y) : x(_x), y(_y) {}
    Point2D() : x(0), y(0) {}
    Point2D(int n) : x(n), y(n) {}
    friend Point2D operator-(Point2D a);
    double getX() { return x; }
    double getY() { return y; }
    void print() { cout << "(" << getX() << ", " << getY() << ")" << endl; }
};

Point2D operator+(Point2D a, Point2D b)
{
    return Point2D(a.getX() + b.getX(), a.getY() + b.getY());
}

Point2D operator-(Point2D a, Point2D b)
{
    return Point2D(a.getX() - b.getX(), a.getY() - b.getY());
}

Point2D operator*(Point2D a, Point2D b)
{
    return Point2D(a.getX() * b.getX(), a.getY() * b.getY());
}

Point2D operator/(Point2D a, Point2D b)
{
    return Point2D(a.getX() / b.getX(), a.getY() / b.getY());
}

Point2D operator-(Point2D a) // Operatore unario con modificatore friend, usiamo infatti le variabili private e non i metodi pubblici
{
    return Point2D(-a.x, -a.y);
}

int main()
{
    Point2D p(1, 3);
    Point2D p2(3, 4);

    Point2D p3 = p + p2;
    Point2D p4 = p - p2;
    Point2D p5 = p * p2;
    Point2D p6 = p / p2;
    Point2D p7 = -p2;
    Point2D p8 = p + 4; // Promozione da scalare a Point2D tramite apposito costruttore

    p3.print();
    p4.print();
    p5.print();
    p6.print();
    p7.print();
    p8.print();
}
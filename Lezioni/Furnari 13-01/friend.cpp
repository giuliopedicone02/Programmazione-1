#include <iostream>
#include <cmath>
using namespace std;

class Point2D
{
private:
    double x, y;

public:
    Point2D() : x(0), y(0) {}
    Point2D(double _x, double _y) : x(_x), y(_y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    friend void normalizeFriend(Point2D &p);
    friend Point2D sum(Point2D p1, Point2D p2);
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
};

void normalize(Point2D &p)
{
    double mod = sqrt(p.getX() * p.getX() + p.getY() * p.getY());
    p.setX(p.getX() / mod);
    p.setY(p.getY() / mod);
}

void normalizeFriend(Point2D &p) // Possiamo accedere ai valori privati senza usare i metodi set e get grazie al modificatore friend
{
    double mod = sqrt(p.x * p.x + p.y * p.y);
    p.x /= mod;
    p.y /= mod;
}

Point2D sum(Point2D p1, Point2D p2)
{
    return Point2D(p1.x + p2.x, p1.y + p2.y);
}

int main()
{
    Point2D p(2.3, 5.6);

    normalize(p);
    cout << p.getX() << " - " << p.getY() << endl;

    Point2D p1(4.7, 6.4);
    normalize(p1);
    cout << p1.getX() << " - " << p1.getY() << endl;

    Point2D p3(2, 3);
    Point2D p4(5, 8);
    Point2D p5 = sum(p3, p4);
    cout << p5.getX() << " - " << p5.getY() << endl;
}
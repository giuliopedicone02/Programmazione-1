#include <iostream>
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D(double _x, double _y) : x(_x), y(_y) {}
    Point2D() : x(0), y(0) {}
    double getX() { return x; }
    double getY() { return y; }
    friend Point2D operator+(Point2D, Point2D);
    friend Point2D operator-(Point2D, Point2D);
    friend Point2D operator*(Point2D, Point2D);
    Point2D operator/(Point2D a) // Funzione membro
    {
        return Point2D(a.x / this->x, a.y / this->y);
    }
    friend bool operator<(Point2D, Point2D);
    friend bool operator>(Point2D, Point2D);
    friend bool operator==(Point2D, Point2D);

    friend Point2D &operator++(Point2D &);     //++ prefisso
    friend Point2D operator++(Point2D &, int); //++ postfisso
    friend Point2D &operator--(Point2D &);     //-- prefisso
    friend Point2D operator--(Point2D &, int); //-- postfisso

    friend ostream &operator<<(ostream &, Point2D);
};

Point2D operator+(Point2D a, Point2D b)
{
    return Point2D(a.x + b.x, a.y + b.y);
}

Point2D operator-(Point2D a, Point2D b)
{
    return Point2D(a.x - b.x, a.y - b.y);
}

Point2D operator*(Point2D a, Point2D b)
{
    return Point2D(a.x * b.x, a.y * b.y);
}

bool operator<(Point2D a, Point2D b)
{
    if (a.x + a.y < b.x + b.y)
    {
        return true;
    }

    return false;
}

bool operator>(Point2D a, Point2D b)
{
    if (a.x + a.y > b.x + b.y)
    {
        return true;
    }

    return false;
}

bool operator==(Point2D a, Point2D b)
{
    if (a.x == b.x && a.y == b.y)
    {
        return true;
    }

    return false;
}

Point2D &operator++(Point2D &a) // Overloading ++ prefisso
{
    a.x++;
    a.y++;

    return a;
}

Point2D operator++(Point2D &a, int) // Overloading ++ postfisso
{
    Point2D aux = a; // Copia non ancora modificata di a
    a.x++;
    a.y++;
    return aux;
}

Point2D &operator--(Point2D &a) // Overloading -- prefisso
{
    a.x--;
    a.y--;

    return a;
}

Point2D operator--(Point2D &a, int) // Overloading -- postfisso
{
    Point2D aux = a; // Copia non ancora modificata di a
    a.x--;
    a.y--;
    return aux;
}

ostream &operator<<(ostream &s, Point2D p)
{
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; // restituisco il riferimento
}

int main()
{
    Point2D p1(2, 3);
    Point2D p2(3, 3);

    Point2D p3 = p1 + p2;
    cout << "(" << p3.getX() << "," << p3.getY() << ")" << endl;

    if (p1 < p2)
    {
        cout << "P1 minore di P2" << endl;
    }

    cout << p1 << endl;
    cout << --p1 << endl;
    cout << p1-- << endl;
    cout << p1 << endl;
}
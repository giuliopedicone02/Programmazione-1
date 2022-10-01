#include <iostream>
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D(double a, double b) : x(a), y(b) {}

    Point2D(Point2D &p) : x(p.x), y(p.y)
    { // costruttore di copia
        // codice custom
        cout << "costruttore di copia" << endl;
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

int main()
{

    Point2D p1(3, 2);
    Point2D p2(4, 5);

    Point2D p3 = p1; // richiama il costruttore di copia
    Point2D p4(p1);  // richiama il costruttore di copia

    cout << p1.getX() << ", " << p1.getY() << endl;
    cout << p2.getX() << ", " << p2.getY() << endl;

    p2 = p1; // copia automatica membro a membro di C++ non richiama il costruttore di copia
    cout << p2.getX() << ", " << p2.getY() << endl;
}
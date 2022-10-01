#include <iostream>
using namespace std;
class A
{
    int x;
    // B b;
public:
    A(int _x)
    {
        x = _x;
    }

    void f() { cout << "A.f(), x=" << x << endl; }
    int getX() { return x; }
    virtual ~A() {} // Dichiarando virtual il distruttore di A richiama il distruttore della apposita classe "figlia"
};

class B : public A
{
    float y;
    int *z;

public:
    B(int x, float _y) : A(x)
    {
        y = _y;
        z = new int[10];
    }
    void f() { cout << "override di A.f(), x=" << getX() << endl; }
    void g() { cout << "B.g(), y=" << y << endl; }
    ~B()
    {
        delete z;
        cout << "Distruttore di B";
    }
};

int main()
{
    A *a = new B(2, 3);
    delete a;
}
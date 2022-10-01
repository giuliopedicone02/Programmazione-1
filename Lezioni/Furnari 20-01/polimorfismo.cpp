#include <iostream>
using namespace std;

class A
{
protected:
    int x;
    // B b;
public:
    A(){};

    A(int n) : x(n){};

    void f() { cout << "A.f(), x=" << x << endl; }
    int getX() { return x; }
};

class B : public A
{
    float y;

public:
    B() { y = 18; }
    B(int a, float b) : y(b) { x = a; };
    void g() { cout << "B.g(), y=" << y << endl; }
    void f() { cout << "override di A.f(), x=" << getX() << endl; }
};

int main()
{
    A *pa = new A(10);
    B *pb = new B(20, 4.4);
    pb->g();
    pa = pb;
    pa->f();
}
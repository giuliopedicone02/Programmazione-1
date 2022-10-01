#include <iostream>
using namespace std;

class A
{
protected: // A differenza di private è visibile anche alle classi "figlie" ma non al main o altre classi "non figlie"
    int x;
    // B b;
public:
    A()
    {
        x = 10;
    }

    void f() { cout << "A.f(), x=" << x << endl; }
    int getX() { return x; }
};

class B : public A
{
    float y;

public:
    B() { y = 18; }
    void g() { cout << "B.g(), y=" << y << endl; }
    void f() { cout << "override di A.f(), x=" << getX() << endl; }
};

int main()
{
    B obj1;

    obj1.g();
    obj1.f();
    obj1.A::f();
    cout << obj1.getX();
}
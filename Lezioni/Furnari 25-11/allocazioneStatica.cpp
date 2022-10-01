#include <iostream>
using namespace std;

int x = 42;

int getx()
{
    return x;
}

int main()
{
    cout << x << endl;
    int y = getx();
    cout << y << endl;
}
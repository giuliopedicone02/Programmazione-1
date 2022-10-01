#include <iostream>
using namespace std;

template <typename T>
T minimo(T x, T y)
{
    return x < y ? x : y;
}
template <typename T>
T massimo(T x, T y)
{
    return x > y ? x : y;
}

int main()
{
    int x = 3, y = 4;
    cout << minimo(x, y) << endl;
    cout << massimo(x, y) << endl;
}
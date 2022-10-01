#include <iostream>
#include <string>
using namespace std;

string concat(string s1, string s2)
{
    return s1 + s2;
}

string concat(string s1, char s2)
{
    return s1 + s2;
}

int main()
{
    string s1 = "Hello";
    string s2 = "World";

    cout << concat(s1, s2) << endl;
    cout << concat("Hello ", 'W') << endl;
}
#include <iostream>
using namespace std;
int aa = 1, bb = 2;

int a() { cout << aa; };
int b();

int main()
{
    a();
    b();
}

#define aa bb
int b() { cout << aa; };


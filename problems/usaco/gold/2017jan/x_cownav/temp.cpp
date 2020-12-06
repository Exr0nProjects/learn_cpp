// wishing changing std::tie could change the source too
#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    auto t = make_tuple(10, 20, 30);
    int x;
    int& a1=x, a2=x, a3=x;
    int b1, b2, b3, c1, c2, c3;
    tie(a1, a2, a3) = t;
    tie(b1, b2, b3) = t;
    printf("%d %d %d\n", a1, a2, a3);
    printf("%d %d %d\n", b1, b2, b3);
    a1 = 0; printf("changed a1 to 0\n");
    printf("%d %d %d\n", a1, a2, a3);
    printf("%d %d %d\n", b1, b2, b3);
    tie(c1, c2, c3) = t;
    printf("%d %d %d\n", c1, c2, c3);
}


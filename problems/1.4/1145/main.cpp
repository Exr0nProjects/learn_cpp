/*
 * Problem #1145
 */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main ()
{
    int vote, a=0, b=0, c=0, total=0;
    while (cin >> vote)
    {
        switch (vote)
        {
            case -1:
                total += a + b + c;
                cout << "A=" << a << "\nB=" << b << "\nC=" << c << "\nTot=" << a+b+c << endl;
                total /= 2;
                if (a > total) cout << "A-yes";
                else if (b > total) cout << "B-yes";
                else if (c > total) cout << "C-yes";
                else cout << "all-NO";
                return 0;
            case 1:
                ++ a;
                break;
            case 2:
                ++ b;
                break;
            case 3:
                ++ c;
                break;
            default: ++total;
        }
    }

    return 0;
}

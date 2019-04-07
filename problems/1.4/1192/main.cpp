/*
 * Problem #1192
 */

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;


int main ()
{
    int ch = -1, dig=0, alp=0, oth=0, len;

    string inp;

    std::getline(cin, inp, (char) 63);

    len = (int) inp.size();

    for (int i=0; i<len; ++i)
    {
        ch = inp[i];

        if (isalpha(ch)) ++ alp;
        else if (isdigit(ch)) ++ dig;
        else ++ oth;
    }

    //printf("Numbers=%s\nLetters=%s\nOthers=%s", dig, alp, oth);
    cout << "Letters=" << alp << "\n\nDigits=" << dig << "\n\nOthers=" << oth;

    return 0;
}

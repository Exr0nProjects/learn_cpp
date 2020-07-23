/*

NUMBER 9

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ANSSIZE 2005

string a, b;
int alen, blen;
int num1[1000], num2[1000];
int ans[3000];

int main() {
    cin >> a >> b;

    alen = a.size();
    blen = b.size();

    for (int i = alen - 1; i >= 0; i--)
        num1[i] = a[i] - '0';
    for (int i = blen - 1; i >= 0; i--)
        num2[i] = b[i] - '0';

    for (int i = 0; i <= ANSSIZE; i++)
        ans[i] = 0;

    int start = ANSSIZE;
    for (int i = blen - 1; i >= 0; i--, start--) {
        int remainder = 0;
        int curr = start;
        for (int j = alen - 1; j >= 0; j--, curr--) {
            ans[curr] += remainder + num2[i] * num1[j];
            remainder = ans[curr] / 10;
            ans[curr] %= 10;
        }
        if (remainder != 0)
            ans[curr] += remainder;
    }
    bool numstart = false;



    for (int i = 0; i <= ANSSIZE; i++) {
        if (numstart) cout << ans[i];
        else {
            if (ans[i] != 0) {
                numstart = true;
                cout << ans[i];
            }
        }
    }
    if (numstart == false)
        cout << "0";
    cout << endl;

}


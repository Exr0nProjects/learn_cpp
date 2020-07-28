/*

PROBLEM 10
william

*/

#include <iostream>

using namespace std;

int mat[2000][2000];

int main() {
    int n; cin >> n;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int r = i;
            int c = 0;
            for (; r >= 0; --r, c++)
                mat[r][c] = ++curr;

        }
        else {
            int r = 0;
            int c = i;
            for (; c >= 0; --c, ++r)
                mat[r][c] = ++curr;

        }
    }

    for (int i = 1; i < n; i++) {
        if ((i+n) % 2 == 0) {
            int c = n - 1;
            int r = i;
            for (; r < n; ++r, --c)
                mat[r][c] = ++curr;
        }
        else {
            int c = i;
            int r = n - 1;
            for (; c < n; ++c, --r)
                mat[r][c] = ++curr;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
            if (j != n-1) cout << " ";
        }
        cout << endl;
    }
}


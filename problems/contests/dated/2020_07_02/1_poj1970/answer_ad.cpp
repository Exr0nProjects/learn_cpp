#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
using namespace std;
typedef pair <int, int> pii;
#define mp make_pair
#define f first
#define s second
const int maxn = 20;
int n = 19;
int a[maxn][maxn];

pair <int, pii> check_vert(int x, int y, int c) {
    pair <int, pii> ans;
    while (x > 0) {
        if (a[x - 1][y] == c) x--;
        else break;
    }
    //if (a[x-1][y] != c) return mp(0, mp(0, 0));
    ans.f = 0;
    ans.s.f = x;
    ans.s.s = y;
    while (x < n && a[x][y] == c) {
        ans.f++;
        x++;
    }
    return ans;
}

pair <int, pii> check_hori(int x, int y, int c) {
    pair <int, pii> ans;
    while (y > 0) {
        if (a[x][y - 1] == c) y--;
        else break;
    }
    //if (a[x][y-1] != c) return mp(0, mp(0, 0));
    ans.f = 0;
    ans.s.f = x;
    ans.s.s = y;
    while (y < n && a[x][y] == c) {
        ans.f++;
        y++;
    }
    return ans;
}

pair <int, pii> check_d1(int x, int y, int c) {
    pair <int, pii> ans;
    while (x > 0 && y > 0) {
        if (a[x - 1][y - 1] == c) {
            x--;
            y--;
        }
        else break;
    }
    //if (a[x-1][y-1] != c) return mp(0, mp(0, 0));
    ans.f = 0;
    ans.s.f = x;
    ans.s.s = y;
    while (x < n && y < n && a[x][y] == c) {
        ans.f++;
        x++;
        y++;
    }
    return ans;
}

pair <int, pii> check_d2(int x, int y, int c) {
    pair <int, pii> ans;
    while (x < n - 1 && y > 0) {
        if (a[x + 1][y - 1] == c) {
            x++;
            y--;
        }
        else break;
    }
    //if (a[x+1][y-1] != c) return mp(0, mp(0, 0));
    ans.f = 0;
    ans.s.f = x;
    ans.s.s = y;
    while (x >= 0 && y < n && a[x][y] == c) {
        ans.f++;
        x--;
        y++;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        bool is_ans = false;
        for (int i = 0; i < 19; i++) {
            if (is_ans) break;
            for (int j = 0; j < 19; j++) {
                if (!a[i][j]) continue;
                pair <int, pii> v = check_vert(i, j, a[i][j]);
                pair <int, pii> h = check_hori(i, j, a[i][j]);
                pair <int, pii> d1 = check_d1(i, j, a[i][j]);
                pair <int, pii> d2 = check_d2(i, j, a[i][j]);
                if (v.f == 5) {
                    is_ans = true;
                    printf("%d\n%d %d\n", a[i][j], v.s.f + 1, v.s.s + 1);
                    break;
                }
                if (h.f == 5) {
                    is_ans = true;
                    printf("%d\n%d %d\n", a[i][j], h.s.f + 1, h.s.s + 1);
                    break;
                }
                if (d1.f == 5) {
                    is_ans = true;
                    printf("%d\n%d %d\n", a[i][j], d1.s.f + 1, d1.s.s + 1);
                    break;
                }
                if (d2.f == 5) {
                    is_ans = true;
                    printf("%d\n%d %d\n", a[i][j], d2.s.f + 1, d2.s.s + 1);
                    break;
                }
            }
        }
        if (!is_ans) printf("%d\n", 0);
    }
}



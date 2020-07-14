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
#define f first
#define s second
const int maxn = 4000010, maxm = 40010;
int n;
int a[maxn];
int ans[maxm];

int gcd(int a, int b) {
    if (b > a) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    while (scanf("%d", &n) == 1) {
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            int g = a[i];
            for (int j = i; j < n; j++) {
                g = gcd(g, a[j]);
                ans[g]++;
            }
        }
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);
            printf("%d\n", ans[x]);
        }
    }
}


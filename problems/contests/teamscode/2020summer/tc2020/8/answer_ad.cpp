#include <bits/stdc++.h>
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
const int maxn = 10010;
int a[maxn], ans[maxn];
char m[maxn], p[maxn][60];

int main() {
    int n, ml;
    scanf("%d%d", &n, &ml);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < ml; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            cin >> p[i][j];
        }
    }
    int cnt = 0, fans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = -ml; j < ml; j++) {
            cnt = 0;
            for (int k = 0; k < a[i] && j + k < ml; k++) {
                if (j + k < 0) continue;
                if (m[j + k] == p[i][k]) cnt++;
            }
            ans[i] = max(ans[i], cnt);
        }
        fans += ans[i];
    }
    printf("%d", fans);
}


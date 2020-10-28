#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace::std;

typedef long long ull;

int N, Q;
ull bit1[100005], bit2[100005];

#define par(x) (x & (-x))

ull prefix(ull *bit, int a) {
    ull sum = 0;
    for (; a; a -= par(a))
        sum += bit[a];
    return sum;
}

ull prefix(int a) {
    return prefix(bit1, a) * a - prefix(bit2, a);
}

ull query(int a, int b) {
    if (a)
        return prefix(b) - prefix(--a);
    else
        return prefix(b);
}

void update(ull *bit, int a, ull v) {
    for (; a <= N; a += par(a))
        bit[a] += v;
}

void update(int a, int b, ull v) {
    update(bit1, a, v);
    update(bit1, b + 1, -v);
    update(bit2, a, v * (a-1));
    update(bit2, b + 1, -v * b);
}

int main(void) {
    scanf("%d%d", &N, &Q);
    for (int i = 1, a; i <= N; i++) {
        scanf("%d", &a);
        update(i, i, a);
    }

    int t, a, b;
    ull c;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &t);
        if (t == 2) {
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(a, b));
        }
        else {
            scanf("%d%d%lld", &a, &b, &c);
            update(a, b, c);
        }
    }
}


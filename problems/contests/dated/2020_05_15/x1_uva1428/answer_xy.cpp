#include <cstdio>
#include <cstring>

using namespace std;

#define lc (o<<1)
#define rc ((o<<1)|1)

const int maxn = 20000 + 10;
const int maxm = 100000;

int C[maxm<<2];
int lev[maxn], l[maxn], r[maxn];

void build(int o, int L, int R) {
    C[o] = 0;
    if(L == R) return;
    int M = (L + R) >> 1;
    build(lc, L, M);
    build(rc, M+1, R);
}

void update(int o, int L, int R, int x) {
    if(L == R) {
        C[o]++;
        return;
    }
    int M = (L + R) >> 1;
    if(x <= M) update(lc, L, M, x);
    else update(rc, M+1, R, x);
    C[o] = C[lc] + C[rc];
}

int query(int o, int L, int R, int ql, int qr) {
    if(ql <= L && R <= qr) return C[o];
    int M = (L + R) >> 1;
    int ret = 0;
    if(ql <= M) ret += query(lc, L, M, ql, qr);
    if(qr > M) ret += query(rc, M+1, R, ql, qr);
    return ret;
}

int main()
{
    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) scanf("%d", &lev[i]);
        build(1, 1, maxm);
        update(1, 1, maxm, lev[1]);
        for(int i = 2; i < N; i++) {
            l[i] = query(1, 1, maxm, 1, lev[i]);
            update(1, 1, maxm, lev[i]);
        }
        build(1, 1, maxm);
        update(1, 1, maxm, lev[N]);
        for(int i = N-1; i > 0; i--) {
            r[i] = query(1, 1, maxm, 1, lev[i]);
            update(1, 1, maxm, lev[i]);
        }
        long long ret = 0;
        for(int i = 2; i < N; i++)
            ret += (long long)l[i] * (N - i - r[i]) + (long long)(i - 1 - l[i]) * r[i];
        printf("%lld\n", ret);
    }
    return 0;
}


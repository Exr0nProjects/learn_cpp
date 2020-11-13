/*
 * Problem 1001 (duck/1001)
 * Create time: Thu 12 Nov 2020 @ 16:29 (PST)
 * Accept time: [!meta:end!]
 *
 */


#include <utility>
void sort(unsigned *a, int n) {
    unsigned c[n+5];
    unsigned *b = c, pos[300];
    for (unsigned s=0; s<32; s+=8)
    {
        memset(pos, 0, sizeof pos); // FIX: clears-- pos
        //printf("%x\n", (0xff<<s));
        //printf("    :"); for (int i=0; i<n; ++i) printf("%x ", a[i]>>s&0xff); printf("\n");
        for (int i=0; i<n; ++i) ++pos[a[i]>>s&0xff];
        //for (int i=0; i<256; ++i) if (pos[i]) printf("%3u", pos[i]); printf("\n");
        for (int i=1; i<256; ++i) pos[i] += pos[i-1];
        //for (int i=0; i<256; ++i) if (pos[i]) printf("%3u", pos[i]); printf("\n");
        //printf("epic\n");
        //for (int i=n-1; ~i; --i) printf("setting %3d = %3d = %3d\n", a[i], a[i]>>s&0xff, pos[a[i]>>s&0xff]-1);
        for (int i=n-1; ~i; --i) b[--pos[a[i]>>s&0xff]] = a[i]; // FIX: bounds--start at n-1 not at n cuz zero index smah
        //printf("epic\n");
        //for (int i=0; i<n; ++i) printf("%5u", b[i]); printf("\n");
        std::swap(a, b);
    }
}

int main()
{
    unsigned a[12] = { 2, 1, 4, 3, 262, 5, 10, 9, 8, 7 };
    sort(a, 10);
    for (int i=0; i<10; ++i) printf("%5u", a[i]); printf("\n");
}


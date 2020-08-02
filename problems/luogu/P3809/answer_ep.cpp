#include <cstdio>
#include <cstring>
const int MX = 1000111;

int sa[MX], rk[MX], tmp[MX], pos[MX];

void calc(char *s) {
    int len = strlen(s + 1), mx = 255;
    for (int i = 1; i <= len; ++i) {
        rk[i] = s[i];
        sa[i] = i;
    }
    for (int i = 1; i >> 1 < len; i <<= 1) {
        // radix sort for second keyword
        int k = i >> 1, p = k;
        for (int i = 1; i <= k; ++i) tmp[i] = len - i + 1; // for the last k pairs, the second number is 0
        for (int i = 1; i <= len; ++i) if (sa[i] > k) tmp[++p] = sa[i] - k;
        printf("tmp_%d: ", k); for (int i=1; i<=len; ++i) printf("%3d", tmp[i]); printf("\n");
        // radix sort for first keyword
        for (int i = 1; i <= len; ++i) pos[i] = 0; // clear buckets
        for (int i = 1; i <= len; ++i) ++pos[rk[i]]; // store the number of elements
        for (int i = 1; i <= mx; ++i) pos[i] += pos[i - 1]; // calculate the prefix sum
        for (int i = len; i; --i) sa[pos[rk[tmp[i]]]--] = tmp[i]; // put the elements in reverse order
        printf("sa_%d:  ", k); for (int i=1; i<=len; ++i) printf("%3d", tmp[i]); printf("\n");
        // calculate rank
        for (int i = 1; i <= len; ++i)
            tmp[sa[i]] = tmp[sa[i - 1]] + (rk[sa[i]] != rk[sa[i - 1]] || rk[sa[i] + k] != rk[sa[i - 1] + k]);
        for (int i = 1; i <= len; ++i) rk[i] = tmp[i];
        printf("rk_%d:  ", k); for (int i=1; i<=len; ++i) printf("%3d", tmp[i]); printf("\n");
        printf("\n");

        mx = rk[sa[len]];
        if (mx == len) break;
    }
}

char inp[MX];

int main()
{
    scanf("%s", inp+1);
    //N = strlen(inp+1);
    calc(inp);

	return 0;
}


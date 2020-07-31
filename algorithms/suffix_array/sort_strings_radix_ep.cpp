void calc(char *s) {
    int len = strlen(s + 1), mx = 255;
    for (int i = 1; i <= len; ++i) {
        rk[i] = s[i];
        sa[i] = i;
    }
    for (int i = 1; i >> 1 < len; i <<= 1) {
        // radix sort for second keyword
        int k = i >> 1, p = k;
        for (int j = 1; j <= k; ++j) tmp[j] = len - j + 1; // for the last k pairs, the second number is 0
        for (int j = 1; j <= len; ++j) if (sa[j] > k) tmp[++p] = sa[j] - k;
        // radix sort for first keyword
        for (int j = 1; j <= mx; ++j) pos[j] = 0; // clear buckets
        for (int j = 1; j <= len; ++j) ++pos[rk[j]]; // store the number of elements
        for (int j = 1; j <= mx; ++j) pos[j] += pos[j - 1]; // calculate the prefix sum
        for (int j = len; j; --j) sa[pos[rk[tmp[j]]]--] = tmp[j]; // put the elements in reverse order
        // calculate rank
        for (int j = 1; j <= len; ++j)
            tmp[sa[j]] = tmp[sa[j - 1]] + (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + k] != rk[sa[j - 1] + k]);
        for (int j = 1; j <= len; ++j) rk[j] = tmp[j];
        mx = rk[sa[len]];
        if (mx == len) break;
    }
}


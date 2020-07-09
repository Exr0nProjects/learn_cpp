void kmp(char c[], int len) {
  nxt[0] = -1;
  for (int i = 1; i < len; ++i) {
    for (nxt[i] = nxt[i - 1]; ~nxt[i] && c[nxt[i] + 1] != c[i];
         nxt[i] = nxt[nxt[i]])
      ;
    if (c[nxt[i] + 1] == c[i])
      ++nxt[i];
  }
}


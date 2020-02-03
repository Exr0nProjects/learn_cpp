#include <cstdio>
int n, L, cnt;
int S[100];
int dfs(int cur)
{
  if (cnt++ == n)
  {
    for (int i = 0; i < cur; i++)
    {
      if (i % 64 == 0 && i > 0)
        printf("\n");
      else if (i % 4 == 0 && i > 0)
        printf(" ");
      printf("%c", 'A' + S[i]); // output solution
    }
    printf("\n%d\n", cur);
    return 0;
  }
  for (int i = 0; i < L; i++)
  {
    S[cur] = i;
    int ok = 1;
    for (int j = 1; j * 2 <= cur + 1; j++)
    {
      int equal = 1;
      for (int k = 0; k < j; k++) // Check whether first half equals to second half
        if (S[cur - k] != S[cur - k - j])
        {
          equal = 0;
          break;
        }
      if (equal)
      {
        ok = 0;
        break;
      }
    }
    if (ok)
      if (!dfs(cur + 1))
        return 0;
  }
  return 1;
}
int main()
{
  while (scanf("%d%d", &n, &L) == 2 && n > 0)
  {
    cnt = 0;
    dfs(0);
  }
  return 0;
}

/*
meaning of?
(1) L
(2) cnt
(3) cur
(4) i
(5) j
(6) k
(7) S
*/
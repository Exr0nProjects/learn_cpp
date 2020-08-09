#include <cstdio>

const int MX = 10;
int vis[MX], perm[MX];
void permutations(int len, int cur=0)
{
    if (cur == len) {
        for (int i=0; i<len; ++i)
            printf("%3d", perm[i]);
        printf("\n");
        return;
    }
    for (int i=0; i<len; ++i)
        if (!vis[i])
        {
            vis[i] = 1;
            perm[cur] = i;
            permutations(len, cur+1);
            vis[i] = 0;
        }
}

int main()
{
    permutations(5);
}


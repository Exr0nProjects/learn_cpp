// this is a scam

#include <bits/stdc++.h>
using namespace std;

int T, N;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        int ans = 0;
        for (int i=1; i<=N; ++i)
        {
            int x; scanf("%d", &x);
            if (x == 1) ++ans;
        }
        if (ans & 1) printf("rabbit\n");
        else printf("hamster\n");
    }
}


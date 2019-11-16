// problem 3, 16 nov 2019
// carpet covering problem
#include <bits/stdc++.h>

#define cn const int
#define ca const auto &

using namespace std;
cn MAXSZ = 25; // todo;
int n;
double conv[MAXSZ][MAXSZ];

struct State
{
    int src, cur;
    double val;
    queue<int> prev;
};
queue<State> q;

bool step()
{
    State s = q.front();
    for (int i = 0; i < n; ++i)
    {
        if (i == s.cur)
            continue;
        State r = s;
        r.cur = i;
        r.val *= conv[i][s.cur];
        r.prev.push(i);

        q.pop();

        if (r.prev.size() >= n)
            continue; // chain too long
        else if (i == s.src && r.val > 1.01)
        {
            for (; !r.prev.empty(); r.prev.pop())
            {
                printf("%d ", r.prev.front());
            }
            return true;
        }
        else
            q.push(r);
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    while (n)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j == i)
                    continue;
                double f;
                scanf("%lf", &f);
                conv[i][j] = f;
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            State t;
            t.src = i;
            t.cur = i;
            t.val = 1;
            q.push(t);
        }

        printf("front: %d", q.front().src);

        bool flag = true;
        while (!q.empty())
        {
            if (step())
            {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("no arbitrage sequence exists !\n");

        scanf("%d", &n);
    }
    return 0;
}

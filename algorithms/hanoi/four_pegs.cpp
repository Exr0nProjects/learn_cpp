/*
29 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

#define cn const int 
cn MAXSZ = 20;
cn PEGS = 4;
struct State {
    stack<int> pegs[PEGS];
    int dist = 0;
};

int main ()
{
    int n;
    scanf("%d", &n);

    queue<State> q;
    State start;
    for (int i=n; i>0; --i)
    {
        start.pegs[0].push(i);
    }
    start.dist = 1;
    for (q.push(start); !q.empty(); q.pop())
    {
        for (int i=0; i<PEGS; ++i)
        {
            for (int j=0; j<PEGS; ++j)
            {
                State c = q.front();
                bool _e = true;
                for (int i=0; i<PEGS-1; ++i)
                {
                    _e &= c.pegs[i].empty();
                }
                if (_e && !c.pegs[PEGS-1].empty())
                {
                    printf("Found it! %d", c.dist);
                    return 0;
                }

                if (j == i
                 || c.pegs[i].empty()
                 || c.pegs[i].top() > c.pegs[j].top()
                ) continue;
                c.pegs[j].push(c.pegs[i].top());
                c.pegs[i].pop();
                ++c.dist;
                q.push(c);
            }
        }
    }

    return 0;
}
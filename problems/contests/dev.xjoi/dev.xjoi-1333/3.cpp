// problem 3, 16 nov 2019
// carpet covering problem
#include <bits/stdc++.h>

#define cn const int
#define ca const auto &

using namespace std;
cn MAXSZ = 2 << 11; // todo;
struct Carpet
{
    int y, x, c;
    Carpet(){};
    Carpet(cn _y, cn _x, cn _c)
    {
        y = _y;
        x = _x;
        c = _c;
    }
    bool operator<(const Carpet &o) const { return (x == o.x ? y < o.y : x < o.x); }
} tmp;
vector<Carpet> out;
pair<int, int> dir[6] = {pair<int, int>{0, 0},
                         pair<int, int>{-1, -1},
                         pair<int, int>{1, -1},
                         pair<int, int>{-1, 1},
                         pair<int, int>{1, 1}};

int n, y, x;

char drawn[MAXSZ][MAXSZ]; // todo: debug system to print the carpet pos

void draw(cn y, cn x, cn c, cn s = 0) // pos y, pos x, type, size
{
    if (s == 0)
    {
        out.push_back(Carpet{y, x, c});
        printf("draw: %d %d  %d\n", y, x, c);
        return;
    }
    else
    {
        // this spot
        draw(y, x, c, s - 1);

        int shift = (2 << s) - 1;
        draw(y + dir[c].first * shift, x, ((c + 1) / 2) * 2 - ((c + 1) % 2), s - 1);           // flip y type: `for (int i=1; i<5; ++i) printf("%d -> %d\n", i, ((i+1)/2)*2 - ((i+1)%2));`
        draw(y, x + dir[c].second * shift, ((c + 2) % 4 ? (c + 2) % 4 : 4), s - 1);            // flip x type: `for (int i=1; i<5; ++i) printf("%d -> %d\n", i, ((i+2)%4? (i+2)%4: 4));`
        draw(y + dir[c].first * ((1 << s) - 1), x + dir[c].second * ((1 << s) - 1), c, s - 1); // draw the one that faces the same way.
        /* old redundant code
            // adjacent carpets
            if (c == 1)
            {
                draw(y, x-shift, 3, s-1); // left neighbor
                draw(y-shift, x, 2, s-1); // top neighbor
                draw(y-(1<<s), x-(1<<s), c, s-1);
            }
            else if (c == 4)
            {
                draw(y, x+shift, 2, s-1); // right neighbor
                draw(y+shift, x, 3, s-1); // top neighbor
            }
            else if (c == 2)
            {
                draw(y, x-shift, 4, s-1); // left neighbor
                draw(y+shift, x, 1, s-1); // bottom neighbor
            }
            else if (c == 3)
            {
                draw(y-shift, x, 4, s-1); // top neighbor
                draw(y, x+shift, 1, s-1); // bottom neighbor
            }
            */
    }
}

void starter(cn sx, cn sy, cn quad, cn size = 1)
{
    draw(sy - dir[quad].first * ((1 << size)), sx - dir[quad].second * ((1 << size)), quad, size - 1);
}

int main()
{
    starter(0, 0, 4, 3);
    return 0;

    scanf("%d", &n);
    scanf("%d%d", &y, &x);
    printf("%d %d %d\n", n, y, x);

    for (; n; --n)
    {
    }

    printf("%d\n", n);
    return 0;

    // draw(1, 1, 4);

    // printf("\n\n");
    // draw(1, 1, 4, 1);
    // printf("\n\n");

    // draw(1, 4, 2, 1);
    // printf("\n\n");
    // draw(4, 1, 3, 1);
    // printf("\n\n");
    // draw(4, 4, 1, 1);
    // printf("\n\n");
    // printf("\n");
    // draw(3, 6, 2, 1);
    // printf("\n\n");
}

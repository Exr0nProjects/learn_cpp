/*
 * Problem #1227
 * connected reigons
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double

using namespace std;

struct square
{
    int x, y;
    int group; // -1 = barrier; 0 = uninitialized
};

const int MAXSZ = 110;

int floodfill (square& curr, square grid[][MAXSZ]);

int main ()
{
    square grid[MAXSZ][MAXSZ];
    
    int n, m;
    cin >>n >>m;
    for (int i=0; i<n; ++i)
    {
        char tc;
        for (int j=0; j<m; ++j)
        {
            scanf("%c", &tc);
            if (tc == '\n') { --j; continue; }
            if (tc == '.') grid[i][j].group = -1;
            grid[i][j].x = j; grid[i][j].y = i;
        }
    }

    square * curr;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            curr = &(grid[i][j]);
            if (curr->group == 0) floodfill (*curr, grid);
            
            printf("%2c", (curr->group==0 ? '#' : '.'));
        }
        printf("\n");
    }
    
    
    return 0;
}

inline int floodfill (square& curr, square grid[][MAXSZ])
{
    static int reigons = 0;
    static stack<square> mstk;
    
    if (curr.group != 0) {
        mstk.pop();
        return reigons;
    }
    
    if (mstk.empty()) ++reigons; // entry case
    mstk.pop();
    curr.group = reigons; 
    
    for (int i=-1; i<2; ++i) for (int j=-1; j<2; ++j)
    {
        mstk.push(grid[curr.x+i][curr.y+j]);
    }
    
    while (!mstk.empty()) floodfill(mstk.top(), grid);
    return reigons;
}

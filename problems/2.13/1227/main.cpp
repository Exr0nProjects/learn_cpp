/*
 * Problem #1227
 * connected reigons
 *
 * todo: it seems to be counting the things that aren't valid reigons as reigons, for some reason? should we just swap the input?
 *
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

int floodfill (square grid[][MAXSZ], const int n, const int m, int y, int x, const bool set=true);

int main ()
{
    square grid[MAXSZ][MAXSZ];
    
    int n, m, ans;
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
    
    for (int i=0; i<n; ++i)
	{
		for (int j=0; j<m; ++j) printf("%2c", (grid[i][j].group == -1 ? '.' : '#'));
		printf("\n");
	}
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            if (grid[i][j].group == 0)
			{
				printf("  new empty reigon found!! (%d, %d)\n", j, i);
				ans = floodfill (grid, n, m, i, j);
				printf("  floodfill complete: we have found %d reigons so far...\n", ans);
			}
         //   printf("%2c", (curr->group==0 ? '#' : '.'));
        }
    }
    
    printf("%d", ans);
    
    return 0;
}

inline int floodfill (square grid[][MAXSZ], const int n, const int m, int y, int x, const bool set)
{
	static int reigons = 0;
    
    // exit cases
    if (y < 0 || x < 0 || y > n || x > m) return reigons;
    if (grid[y][x].group != 0) return reigons;
    
    if (set) ++reigons; // entry case
    
    printf("    floodfill called with %d reigons and on grid space (%d, %d)\n", reigons, x, y);
    
    grid[y][x].group = reigons; 
    
    for (int i=-1; i<2; ++i) for (int j=-1; j<2; ++j)
    {
        floodfill(grid, n, m, x+i, y+j, false);
    }
    return reigons;
}



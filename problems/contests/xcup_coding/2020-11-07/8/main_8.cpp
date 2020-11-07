/*
 * Problem 8 (contests/xcup_coding/2020-11-07/8)
 * Create time: Sat 07 Nov 2020 @ 14:26 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
const int MX = 1e2+11;

struct Edge { int t, n; } eg[MX]; int hd[MX], ecnt=2;
int N, ghm[MX], ghm2[MX];

void addEdge(int a, int b, bool n=1)
{
    eg[ecnt].t = b;
    eg[ecnt].n = hd[a];
    hd[a] = ecnt++;
    //if (n) addEdge(b, a, 0);
}

int kdeps(int c, int lay=0)
{
    //F(i, lay) printf("|   "); printf("at %d\n", c);
    for (int e=hd[c]; e; e=eg[e].n)
    {
        //F(i, lay) printf("|   "); printf("    -> %d\n", eg[e].t);
        int g = kdeps(eg[e].t);
        if (g > ghm[c]) ghm2[c] = ghm[c], ghm[c] = g;
        else if (g > ghm2[c]) ghm2[c] = g;
    }
    //F(i, lay) printf("|   "); printf(";;;;;\n");
    return ghm[c]+1;
}

int main()
{
    //sc(N);
    scanf("%d", &N);
    for (int i=0; i<=N; ++i)
    {
        string line;
        getline(cin, line);
        stringstream st(line);
        int c, d; st >> c;
        while (st >> d) addEdge(c, d);
        //printf("$ ");
    }

    kdeps(1);
    //for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%3d", ghm[i]); printf("\n");
    //for (int i=1; i<=N; ++i) printf("%3d", ghm2[i]); printf("\n");

    printf("%d\n", ghm[1]+1);
    int mxw = 0;
    for (int i=1; i<=N; ++i) mxw = max(mxw, ghm[i] + ghm2[i]);
    printf("%d\n", mxw+1);
}


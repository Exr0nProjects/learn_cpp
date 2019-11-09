/*
ID: spoytie2
TASK: namenum
LANG: C++14
*/

/*
 * Problem [!meta:pid!] (usaco/training/namenum)
 * Created Sun 27 Oct 2019 @ 17:28 (PDT)
 * Accepted Sun 03 Nov 2019 @ 14:10 (PST)
 *
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define cn const int
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
FILE *fin = fopen("namenum.in", "r");
FILE *dict = fopen("dict.txt", "r");
FILE *fout = fopen("namenum.out", "w+");

const int MAXSZ = -1; // todo

char nums[300] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'};

bool check(const string name, const string cmp)
{
    if (name.length() != cmp.length()) return false;
    for (int i=0; i<name.length(); ++i)
    {
        if (nums[name[i]-'A'] != cmp[i]) return false;
    }
    return true;
}

int main()
{
    char c[30];
    fscanf(fin, "%s", c);
    string cmp =  c;

    printf("starting input\n");

    bool output = false;
    for (int i = 0; i < 5000; ++i)
    {
       
        fscanf(dict, "%s", c);
        if (c[0] == '\n')
            printf("%d\n", i);
        if (check(c, cmp))
        {
            fprintf(fout, "%s\n", c);
            output = true;
        }
    }

    if (! output) fprintf(fout, "NONE\n");

    return 0;
}

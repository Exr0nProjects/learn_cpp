/*
ID: spoytie2
TASK: castle
LANG: C++14
*/

/*
 * Problem castle ([!meta:srcpath!])
 * Create time: Tue 18 Feb 2020 @ 16:35 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "castle");

using namespace std;
const int MX = 55;
int W, H;

// types and encoding
typedef int room_id;
typedef int room_sz;
inline int coord_id(cn i, cn j)
{
    return i*W+j +1;
}

// cell djs -> room
room_id djs_f[MX*MX];
room_sz djs_s[MX*MX];
room_id find(room_id n)
{
    if (djs_f[n] != n)
        djs_f[n] = find(djs_f[n]);
    return djs_f[n];
}
void merge(room_id a, room_id b)
{
    a = find(a);
    b = find(b);
    if (a == b) return; // FIX: don't merge same set, will screw up size count
    if (djs_s[a] < djs_s[b])
        swap(a, b);
    djs_s[a] += djs_s[b];
    djs_f[b] = a;
}

int main()
{
    setIO();
    scanf("%d%d", &W, &H);
    iota(djs_f, djs_f+W*H, 0);
    FOR(i, W*H) djs_s[i] = 1; // FIX: remember to init djs arrays
    FOR(i, H)
    {
        FOR(j, W)
        {
            int c;
            scanf("%d", &c);
            //printf("(%d %d): ", i, j);
            if (!(c & 1) && j > 0) // west wall
            {
                //printf("west ");
                merge(coord_id(i, j), coord_id(i, j-1));
            }
            if (!(c & 2) && i > 0) // north wall
            {
                //printf("north ");
                merge(coord_id(i, j), coord_id(i-1, j));
            }
            //printf("\n");
        }
    }

    printf("   "); FOR(i, W) printf("%3d", i); printf("\n");
    FOR(i, H)
    {
        printf("%3d", i);
        FOR(j, W)
            printf("%3c", '@' + find(coord_id(i, j)));
        printf("\n");
    }
    set<int> _debug_rooms;
    FOR(c, H*W) _debug_rooms.insert(find(c+1));
    TRAV(r, _debug_rooms) printf("room %c has size %d\n", '@' + r, djs_s[r]);


    // output og castle stats
    set<int> rooms;
    room_sz largest_room = 0;
    FOR(c, H*W)
    {
        rooms.insert(find(c+1));
        largest_room = max(largest_room, djs_s[find(c+1)]);
    }

    printf("%d\n%d\n", rooms.size(), largest_room);

    // wall removal
    pair<pii, char> to_remove;
    int result_size = 0;
    FOR(c, W-1)
    {
        FORR_(r, 1, H)
        {
            printf("trying %d %d - ", c, r);
            room_id curr = find(coord_id(r, c));
            room_id east = find(coord_id(r, c+1));
            room_id north = find(coord_id(r+1, c));
            if (curr != north) // north is a different room
                if (djs_s[curr]+djs_s[north] > result_size)
                {
                    result_size = djs_s[curr] + djs_s[north];
                    to_remove = {{c, r}, 'N'};
                    printf("north(%d) ", result_size);
                }
            if (curr != east) // east is a different room
                if (djs_s[curr] + djs_s[east] > result_size)
                {
                    result_size = djs_s[curr] + djs_s[east];
                    to_remove = {{c, r}, 'E'};
                    printf("east(%d) ", result_size);
                }
            printf("\n");
        }
    }

    printf("%d\n%d %d %c\n", result_size, to_remove.F.S+1, to_remove.F.F+1, to_remove.S);

    return 0;
}

/*
2 1
4 1
=> 2 1 2 1 1 E

*/

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}

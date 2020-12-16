/*
 * Problem ANARC07G (spoj/ANARC07G)
 * Create time: Tue 15 Dec 2020 @ 18:27 (PST)
 * Accept time: [!meta:end!]
 * tree dp
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MX = 1e5+10;

ll S, F, dp[MX];
map<string, ll> name_id;
ll namein(string &s)
{
    if (!name_id.count(s))
        printf("%3d: %s\n", name_id.size()+1, s.c_str()),
        name_id[s] = name_id.size()+1;
    return name_id[s];
}

struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge(ll u, ll v)
{
    printf("addEdge %d -> %d\n", u, v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
}

int main()
{
    scanf("%d%d", &S, &F);
    while (S > 0)
    {
        printf("\n\n\n\n\n");
        name_id.clear();
        memset(dp, 0x3f, sizeof dp);
        memset(eg, 0, sizeof eg);
        memset(hd, 0, sizeof hd);
        while (true)
        {
            string line; getline(cin, line);
            stringstream ss(line);
            if (ss.peek() <= '9') { ss >> S >> F; break; }
            string name; ss >> name;
            ll parent = namein(name);
            while (ss >> name) addEdge(parent, namein(name));
        }
    }
}

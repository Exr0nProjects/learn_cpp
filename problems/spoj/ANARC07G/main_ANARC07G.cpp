/*
 * Problem ANARC07G (spoj/ANARC07G)
 * Create time: Tue 15 Dec 2020 @ 18:27 (PST)
 * Accept time: [!meta:end!]
 * tree dp
 */
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define f first
#define s second
using namespace std;

const ll MX = 1e5+10;
typedef pair<ll, ll> Ret;

ll S, F, tS, tF, N;

Ret dp[MX][2];
map<string, ll> name_id;
ll namein(string &s)
{
    if (!name_id.count(s))
        //printf("%3d: %s\n", name_id.size()+1, s.c_str()),
        name_id[s] = name_id.size()+1;
    return name_id[s];
}

struct Edge { ll t, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge(ll u, ll v)
{
    //printf("addEdge %d -> %d\n", u, v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
}

Ret comb(Ret &a, Ret b)
{
    a.f += b.f, a.s += b.s;
    return a;
}

Ret cmin(Ret a, Ret b)
{
    const ll ca = a.s*S + a.f*F;
    const ll cb = b.s*S + b.f*F;
    if (ca < cb || (ca == cb && a.f+a.s < b.f+b.s))
        return a;
    return b;
}

Ret op(ll c, bool need, ll d=0)
{
    //for (ll i=1; i<=d; ++i) printf("|   "); printf("dp %d  (%d)\n", c, need);
    if (dp[c][need].f + dp[c][need].s) return dp[c][need];
    Ret no = mp(1, 0), yes = mp(0, 0);
    for (int e=hd[c]; e; e=eg[e].n)
        comb(no,  op(eg[e].t, 0, d+1)),
        comb(yes, op(eg[e].t, 1, d+1));

    if (need) ++yes.s;
    dp[c][need] = cmin(yes, no);
    //for (ll i=1; i<=d; ++i) printf("|   "); printf("=> %d, %d\n", cmin(yes, no).s, cmin(yes, no).f);
    return dp[c][need];
}

int main()
{
    scanf("%d%d\n", &S, &F);
    ll cs = 0;
    while (++cs, S > 0)
    {
        //printf("\n\n\n\n\n");
        name_id.clear();
        memset(eg, 0, sizeof eg);
        memset(hd, 0, sizeof hd);
        while (true)
        {
            string line; getline(cin, line);
            stringstream ss(line);
            if (ss.peek() <= '9') { ss >> tS >> tF; break; }
            string name; ss >> name;
            ll parent = namein(name);
            while (ss >> name) addEdge(parent, namein(name));
        }
        N = name_id.size();
        for (int i=1; i<=N; ++i)
            dp[i][0] = dp[i][1] = mp(0, 0);

        Ret ans = mp(0, 0);
        for (int i=1; i<=N; ++i)
        //{
        //    printf("i %d (%d, %d)\n", i, dp[i][0].f, dp[i][0].s);
            if (!(dp[i][1].s + dp[i][1].f))
            //printf("epic %d \n", i),
            comb(ans, op(i, 1));
        //}

        printf("%d. %d %d %d\n", cs, ans.s, ans.f, ans.f*F + ans.s*S);

        S=tS, F=tF;  // ♫ what can i say except BRUH
    }
}

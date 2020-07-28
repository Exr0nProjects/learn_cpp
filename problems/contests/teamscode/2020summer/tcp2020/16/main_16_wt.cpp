/*

problem 16

*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

#define ll long long

struct Star
{
    pair<ll,ll> c;
    int id;
};

int n, bit[32000], ans[16000];
map<ll,ll> chg;
Star stars[32000];

void update(int ind) {
    ++ind;
    while (ind <= n) {
        ++bit[ind];
        ind += (ind & (-ind));
    }
}

ll query(int ind) {
    ++ind;
    ll ans = 0;
    while (ind > 0) {
        ans += bit[ind];
        ind -= (ind & (-ind));
    }
    return ans;
}

bool operator<(Star a, Star b) {
    if (a.c.second == b.c.second)
        return (a.c.first < b.c.first);
    return (a.c.second < b.c.second);
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        bit[i] = 0;
        ans[i] = 0;
    }
    for (int i = 0; i < n;  ++i) {
        cin >> stars[i].c.first >> stars[i].c.second;
        chg[stars[i].c.first] = 0;
        chg[stars[i].c.second] = 0;
        stars[i].id = i;
    }

    int cnt = 0;
    for (map<ll,ll>::iterator it = chg.begin(); it != chg.end(); ++it)
        chg[it->first] = cnt++;

    for (int i = 0; i < n; i++) {
        stars[i].c.first = chg[stars[i].c.first];
        stars[i].c.second = chg[stars[i].c.second];
    }

    sort(stars, stars+n);

    for (int i = 0; i < n; i++) {
        //cout << stars[i].c.first << " " << stars[i].c.second << endl;
        ans[query(stars[i].c.first)]++;
        update(stars[i].c.first);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}


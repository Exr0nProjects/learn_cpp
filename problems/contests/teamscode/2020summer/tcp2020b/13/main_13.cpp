// adopted from alex
#include <bits/stdc++.h>
using namespace std;
const int MX = 100100;
vector <vector <int> > a(MX);
int deep1[MX], thru1[MX];
int deep2[MX]; //thru2[MX];
int findeep(int cur, int prev) {
    int fir = 0, sec = 0;
    for (int i = 0; i < a[cur].size(); i++) {
        if (a[cur][i] == prev) continue;
        int t = findeep(a[cur][i], cur) + 1;
        if (t > fir) {
            //thru2[cur] = thru1[cur];
            thru1[cur] = a[cur][i];
            sec = fir;
            fir = t;
        } else if (t > sec) {
            //thru2[cur] = a[cur][i];
            sec = t;
        }
    }
    deep1[cur] = fir;
    deep2[cur] = sec;
    return deep1[cur];
}
void nextdeep(int cur, int pre=0, int mxl=0)
{
    //printf("%d from %d max %d\n", cur, pre, mxl);
    if (mxl > deep1[cur])
    {
        //thru2[cur] = thru1[cur];
        thru1[cur] = pre;
        deep2[cur] = deep1[cur];
        deep1[cur] = mxl;
    }
    else if (mxl > deep2[cur])
    {
        //thru2[cur] = pre;
        deep2[cur] = mxl;
    }
    //printf("    deepest %d thru %d, other %d\n", deep1[cur], thru1[cur], deep2[cur]);
    for (int i=0; i<a[cur].size(); ++i)
        if (a[cur][i] != pre)
        {
            if (thru1[cur] == a[cur][i])
                nextdeep(a[cur][i], cur, 1+deep2[cur]);
            else
                nextdeep(a[cur][i], cur, 1+deep1[cur]);
        }
}
int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    findeep(1, -1);
    //for (int i = 1; i <= n; i++) { cout << deep1[i] << " " << deep2[i] << endl; }
    nextdeep(1);

    int minx = 1<<25;
    set<int> mins;
    for (int i=1; i<=n; ++i)
    {
        if (minx > deep1[i])
        {
            minx = deep1[i];
            mins.clear();
        }
        if (minx == deep1[i])
            mins.insert(i);
    }

    //for (int i = 1; i <= n; i++) { cout << deep1[i] << " " << deep2[i] << endl; }
    bool g = 0;
    for (set<int>::iterator it=mins.begin(); it != mins.end(); ++it)
    {
        if (!g) g = 1;
        else printf(" ");
        printf("%d", *it);
    }
}


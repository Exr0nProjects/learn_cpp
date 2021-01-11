/*
 * Problem smallest-sufficient-team (leetcode/smallest-sufficient-team)
 * Create time: Sat 09 Jan 2021 @ 17:05 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stdout, __VA_ARGS__)
using namespace std;

const ll MX = 17;
const ll MXN = 64;
ll dp[MXN][1<<MX], pre[MXN][1<<MX];

class Solution {
    map<string, ll> sid;
    ll id(string &skill)
    {
        if (!sid.count(skill)) sid[skill] = sid.size();
        return sid[skill];
    }
    ll mask(vector<string> &person)
    {
        ll ret = 0;
        for (auto s : person)
            ret |= 1<<id(s);
        return ret;
    }
    void names(ll x, ll M,  vector<string>& req_skills)
    {
        //db("(%d) ", x);
        //for (int i=0; i<M; ++i) if (x>>i&1) cerr << req_skills[i] << " "; else for (int j=0; j<=req_skills[i].size(); ++j) db(" ");
        //cerr << endl;
    }
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        ll N = people.size(), M = req_skills.size();
        //db("n %d m %d\n", N, M);

        memset(dp, 0x3f, sizeof dp);

        dp[0][0] = 0; for (int x=1; x<1<<M; ++x) if (!(x & ~mask(people[0]))) dp[0][x] = 1, pre[0][x] = 1;    // FIX: base case
        for (int i=1; i<N; ++i)
            for (int x=0; x<1<<M; ++x)
            {
                dp[i][x] = dp[i-1][x], pre[i][x] = 0; // don't take this person
                if (dp[i][x] > dp[i-1][x&~mask(people[i])]+1)
                    dp[i][x] = dp[i-1][x&~mask(people[i])]+1, pre[i][x] = 1;
                //db("i %d needs %10d for ", i, dp[i][x]); names(x, M, req_skills);
            }

        //ll aid = 0;
        //for (int i=1; i<N; ++i)
        //    if (dp[i][(1<<M)-1] < dp[aid][(1<<M)-1])
        //        aid = i;
        //db("answer id = %d\n", aid);
        ll cur = (1<<M)-1;
        vector<int> ret;
        for (int i=N-1; ~i; --i) if (pre[i][cur])
            cur &= ~mask(people[i]), ret.push_back(i);
        return ret;
    }
};

int main()
{
    Solution s{};
    vector<string> skills;
    vector<vector<string> > people;
    ll N, M; scanf("%lld%lld", &M, &N);
    string skill;
    for (int i=1; i<=M; ++i) cin >> skill, skills.push_back(skill);
    for (int i=1; i<=N; ++i)
    {
        people.push_back(vector<string>{});
        int n; scanf("%d", &n); string skill;
        for (int j=1; j<=n; ++j) cin >> skill, people[people.size()-1].push_back(skill);
    }
    for (auto s : s.smallestSufficientTeam(skills, people)) cout << s << endl;
}

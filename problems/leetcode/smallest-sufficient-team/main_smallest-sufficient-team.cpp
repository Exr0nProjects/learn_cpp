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

const ll MX = 16;
const ll MXN = 64;
ll dp[MX][1<<MX], pre[MX][1<<MX];

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
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        ll N = people.size(), M = req_skills.size();

        memset(dp, 0x3f, sizeof dp);

        for (int i=0; i<N; ++i)
            for (int x=0; x<1<<M; ++i)
            {
                db("%d %d\n", i, x);
                dp[i][x] = dp[i-1][x], pre[i][x] = 0; // don't take this person
                if (dp[i][x] > dp[i-1][x&~mask(people[i])]+1)
                    dp[i][x] = dp[i-1][x&~mask(people[i])]+1, pre[i][x] = 1;
            }

        ll aid = 0;
        for (int i=1; i<N; ++i)
            if (dp[i][0] < dp[aid][0])
                aid = i;
        db("seg\n");
        ll cur = 0;
        vector<int> ret;
        for (int i=0; i<N; ++i) if (pre[i][cur])
            cur |= mask(people[i]), ret.push_back(i);
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

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

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

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
}

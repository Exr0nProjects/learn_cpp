/*
 * Problem find-the-shortest-superstring (leetcode/find-the-shortest-superstring)
 * Create time: Sun 10 Jan 2021 @ 20:48 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
#define MX 13
#define LEN 25

class Solution {
    string dp[1<<MX][LEN];
    ll overlap[MX][MX];
public:
    string shortestSuperstring(vector<string>& A) {
        ll N = A.size();

        // calculate max pairwise overlap

    }
};


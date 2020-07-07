#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
using namespace std;
typedef pair <int, int> pii;
#define f first
#define s second
string s1, s2;
string a[1000], b[1000];
int dp[1000][1000];

bool cmp(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

int main() {
    int cs = 0;
    while (!cin.eof()) {
        getline(cin, s1);
        getline(cin, s2);
        if (!s1.size() || !s2.size()) {
            printf("%2d. Blank!\n", ++cs);
            continue;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (!isalpha(s1[i]) && !isdigit(s1[i])) s1[i] = ' ';
        }
        for (int i = 0; i < s2.size(); i++) {
            if (!isalpha(s2[i]) && !isdigit(s2[i])) s2[i] = ' ';
        }
        s1 += " !\n";
        stringstream ss1(s1);
        int cnt1 = 0;
        while (ss1 >> a[++cnt1]) {
            if (a[cnt1][0] == '!') break;
        }
        s2 += " !\n";
        stringstream ss2(s2);
        int cnt2 = 0;
        while (ss2 >> b[++cnt2]) {
            if (b[cnt2][0] == '!') break;
        }

        //printf("%d %d\n", cnt1, cnt2);
        //for (int i = 1; i < cnt1; i++) {
        //    cout << a[i] << endl;
        //}
        //for (int i = 1; i < cnt2; i++) {
        //    cout << b[i] << endl;
        //}

        for (int i = 1; i < cnt1; i++) {
            for (int j = 1; j < cnt2; j++) {
                if (cmp(a[i], b[j]))
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    //printf("%3d %3d same!\n", i, j);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        printf("%2d. Length of longest match: %d\n", ++cs, dp[cnt1 - 1][cnt2 - 1]);
    }
}


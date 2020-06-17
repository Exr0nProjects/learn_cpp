#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
const int maxn = 100000+5;
int L, T, O;
int set_tag[4*maxn];
int sum[4*maxn];
void pushdown(int node){
    if (set_tag[node]){
        set_tag[node*2+1] = set_tag[node];
        set_tag[node*2+2] = set_tag[node];
        sum[node*2+1] = sum[node];
        sum[node*2+2] = sum[node];
        set_tag[node] = 0;
    }
    return;
}
void update(int node, int l, int r, int ql, int qr, int val){
    if (ql > r || qr < l) return;
    if (ql <= l && qr >= r){
        set_tag[node] = val;
        sum[node] = pow(2, val);
        return;
    }
    pushdown(node);
    int mid = (l+r+1)/2;
    update(node*2+1, l, mid-1, ql, qr, val);
    update(node*2+2, mid, r, ql, qr, val);
    sum[node] = sum[node*2+1]|sum[node*2+2];
    return;
}
int query(int node, int l, int r, int ql, int qr){
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r){
        return sum[node];
    }
    pushdown(node);
    int mid = (l+r+1)/2;
    int left = query(node*2+1, l, mid-1, ql, qr);
    int right = query(node*2+2, mid, r, ql, qr);
    return left|right;
}
int main(){
    while (scanf("%d%d%d", &L, &T, &O) == 3){
        memset(set_tag, 0, sizeof(set_tag));
        memset(sum, 0, sizeof(sum));
        update(0, 1, L, 1, L, 1);
        for (int i = 0; i < O; i++){
            char k;
            scanf("\n%c", &k);
            if (k == 'C'){
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);
                if (a > b) swap(a, b);
                update(0, 1, L, a, b, c);
            }
            if (k == 'P'){
                int a, b;
                scanf("%d%d", &a, &b);
                if (a > b) swap(a, b);
                int x = query(0, 1, L, a, b);
                int cnt = 0;
                while (x != 0){
                    if (x%2) cnt++;
                    x /= 2;
                }
                printf("%d\n", cnt);
            }
        }
    }
}


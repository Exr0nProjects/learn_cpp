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
const int maxn = 1010;
struct node{
    node* prv;
    node* nxt = nullptr;
    int v;
    node(node* p, int x) {
        this->prv = p;
        this->v = x;
    }
};
char a[maxn];
int m;

int main() {
    while (scanf(" %1010s", a) > 0) {
        node* st = new node(nullptr, -1);
        node *p = st, *cur;
        for (int i = 0; a[i] >= '0'; i++) {
            cur = new node(p, a[i] - '0');
            p->nxt = cur;
            p = cur;
        }
        node *ed = new node(p, -1);
        p->nxt = ed;
        scanf("%d", &m);
        cur = st->nxt;
        int cnt = 0;
        while (cnt < m) {
            if (cur->v > cur->nxt->v) {
                cur->prv->nxt = cur->nxt;
                cur->nxt->prv = cur->prv;
                cur = cur->prv;
                cnt++;
            }
            else cur = cur->nxt;
        }
        bool z = true;
        cur = st->nxt;
        while (cur != ed) {
            if (z) {
                if (cur->v != 0) {
                    z = false;
                    printf("%d", cur->v);
                }
            }
            else printf("%d", cur->v);
            cur = cur->nxt;
        }
        if (z) printf("0");
        printf("\n");
    }
}



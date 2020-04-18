#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int maxn = 100010;

int n;
double x;//current position of sweep line
struct seg{
    int x1, y1, x2, y2;//cordinates
    int id;//id of segment
};
double eval(seg s) {//returns y coordinate of the segment given x coordinate
    if (s.x1 == s.x2) return s.y1;
    return s.y1 + (s.y2 - s.y1) * (x - s.x1) / (s.x2 - s.x1);
}
bool operator== (seg s1, seg s2) {
    return s1.id == s2.id;
}
bool operator< (seg s1, seg s2) {
    return s1.id != s2.id && eval(s1) < eval(s2);
}

struct point {
    double x, y;//coordinates
    int id;//id of segment
    int tp;//type of point, 0 for start or end, 1 for intersection
    int s1, s2;//if intersection, the two lines that intersect
};
struct cmp{
    bool operator()(point p1, point p2) {
        return p1.x > p2.x;
    }
};

seg s[maxn];
priority_queue <point, vector <point>, cmp> p;
set <seg> act;//active lines

set <pair <double, double> > ans;
point insct(seg s1, seg s2) {
    //first segment is a1x + b1y = c1
    int a1 = s1.y2 - s1.y1;
    int b1 = s1.x1 - s1.x2;
    int c1 = a1 * s1.x1 + b1 * s1.y1;
    //second segment is a2x + b2y = c2
    int a2 = s2.y2 - s2.y1;
    int b2 = s2.x1 - s2.x2;
    int c2 = a2 * s2.x1 + b2 * s2.y1; 

    double det = a1 * b2 - a2 * b1;
    if (!det) {//lines are parallel
        return {0, 0, 0, 0, 0, 0};
    }
    else {
        double x = (double)(c1 * b2 - c2 * b1) / det;
        double y = (double)(c2 * a1 - c1 * a2) / det;
        //check if in both lines
        if (x >= min(s1.x1, s1.x2) && x <= max(s1.x1, s1.x2) &&
            x >= min(s2.x1, s2.x2) && x <= max(s2.x1, s2.x2) &&
            y >= min(s1.y1, s1.y2) && y <= max(s1.y1, s1.y2) &&
            y >= min(s2.y1, s2.y2) && y <= max(s2.y1, s2.y2)) {
                ans.insert({x, y});
                return {x, y, 0, 1, s1.id, s2.id};
        }
        else return {0, 0, 0, 0, 0, 0};
    }
}

void print() {
    for (auto it : act) {
        printf("%d ", it.id);
    }
    printf("\n");
}

int main() {
    printf("NOTE: THIS PROGRAM DOES NOT PRODUCE THE CORRECT OUTPUT!\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        s[i] = {x1, y1, x2, y2, i};
        p.push({(double)x1, (double)y1, i, 0, 0, 0});
        p.push({(double)x2, (double)y2, i, 0, 0, 0});
    }
    while (!p.empty()) {
        point curp = p.top();
        p.pop();
        x = curp.x;
        if (!curp.tp) {
            int curs = curp.id;//current segment
            auto it = act.find(s[curs]);
            if (it != act.end()) {
                auto aft = it, bef = it;
                aft++;            
                if (bef != act.begin() && aft != act.end()) {
                    bef--;
                    point isectp = insct(s[bef->id], s[aft->id]);
                    if (isectp.tp) p.push(isectp);
                }
                act.erase(it);
            }
            else {
                auto it = act.lower_bound(s[curs]);
                if (it != act.end()) {
                    point isectp = insct(s[it->id], s[curs]);
                    if (isectp.tp) p.push(isectp);
                }
                if (it != act.begin()) {
                    it--;
                    point isectp = insct(s[it->id], s[curs]);
                    if (isectp.tp) p.push(isectp);
                }
                act.insert(s[curs]);
            }
        }
	/*
        else {
            auto s1 = act.find(s[curp.s1]);
            auto s2 = act.find(s[curp.s2]);
	    // printf("pre swap"); for (int i=0; i<n; ++i) printf("%3d", s[i].id); printf("\n");
            // swap(s1, s2);
	    // printf("pre swap"); for (int i=0; i<n; ++i) printf("%3d", s[i].id); printf("\n\n");
        }
	*/
    }
    for (auto p : ans) {
        printf("%f %f\n", p.f, p.s);
    }
}


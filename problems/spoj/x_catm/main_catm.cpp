/*
 * Problem catm (spoj/catm)
 * Create time: Sun 17 Jan 2021 @ 11:17 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
ll N, M, T, mx, my, cx, cy, dx, dy;
#define dist(x1, y1, x2, y2) (abs(x1-x2)+abs(y1-y2))

int main()
{
	scanf("%lld%lld%lld", &N, &M, &T);
	for (int i=1; i<=T; ++i) {
		scanf("%lld%lld%lld%lld%lld%lld", &mx, &my, &cx, &cy, &dx, &dy);
		// if (mx   < min(dist(cx, cy, 1, my), dist(dx, dy, 1, my)) ||
		//     my   < min(dist(cx, cy, mx, 1), dist(dx, dy, mx, 1)) ||
		//     N-mx < min(dist(cx, cy, N, my), dist(dx, dy, N, my)) ||
		//     M-my < min(dist(cx, cy, mx, M), dist(dx, dy, mx, M)))
		// just need to check if they form a diagonal of a square with the mouse inside, apparently
		if ((mx - my == cx - cy && mx - my == dx - dy && mx > min(cx, dx) && mx < max(cx, dx)) ||
		    (mx + my == cx + cy && mx + my == dx + dy && mx > min(cx, dx) && mx < max(cx, dx)))
			printf("NO\n");
		else printf("YES\n");
	}
}

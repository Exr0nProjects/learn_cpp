#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <cmath>
#include <set>

using namespace std;
const int MX = 1000111;
int N, closea, closeb;

typedef double dl;
typedef pair<dl, dl> Point;

vector<pair<Point, int> > cloud;		// Point, og_pos
set<pair<dl, int> > active; 			// y coord, cloud idx
queue<set<pair<dl, int> >::iterator> remq; 	// iterators to the active set
dl dist;

inline dl euclidianDistance(const int a, const int b)
{
    return sqrt(pow(cloud[b].first.first-cloud[a].first.first, 2) + pow(cloud[b].first.second-cloud[a].first.second, 2));
}

int main()
{
    scanf("%d", &N);
    for (int n=0; n<N; ++n)
    {
	dl a, b;
	scanf("%lf%lf", &a, &b);
	cloud.emplace_back(make_pair(a, b), n);
    }

    // sort for sweepline on x
    sort(cloud.begin(), cloud.end());
    
    // init min dist vars with first two points
    dist = euclidianDistance(0, 1);
    closea = cloud[0].second;
    closeb = cloud[1].second;

    // init remq and active with first two points
    remq.push(active.emplace(cloud[0].first.second, 0).first);	
    remq.push(active.emplace(cloud[1].first.second, 1).first);
    for (int i=2; i<cloud.size(); ++i)
    {
	// check for new closest
	const auto beg = active.lower_bound(make_pair(cloud[i].first.second - dist, 0));// binary search for lowest (y coord) point in active within bounding box
	const auto end = active.upper_bound(make_pair(cloud[i].first.second + dist, N));// binary search for highest (y coord), see above
	for (auto it=beg; it!=end; ++it)						// for each point between these, aka for each point in the bounding box
	{
	    if (euclidianDistance(it->second, i) < dist)				// if it would form the new closest pair
	    {
		dist = euclidianDistance(it->second, i);				// update dist
		closea = cloud[it->second].second;					// update with original idx of that point
		closeb = cloud[i].second;						// update with original idx of this point
	    }
	}
	// remove from active
	while (!remq.empty() && cloud[i].first.first			// while there are active points and the distance between the sweepline x pos
		- cloud[remq.front()->second].first.first >= dist)	// 	and the farthest back active point x pos is larger than min dist 
	{								// 		(aka should remove that point)
	    active.erase(remq.front());					// remove the farthest point from active
	    remq.pop();						// pop farthest point, check the next one
	}
	// add new point to active
	remq.push(active.emplace(cloud[i].first.second, i).first);	// add the new point to active so others can check dist against it
    }

    printf("Closest pair: %d and %d (dist %lf)\n", closea, closeb, dist);
}

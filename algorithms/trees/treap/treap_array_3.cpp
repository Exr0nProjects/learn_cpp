// 19 April 2020
// UNTESTED
#include <iostream>
#include <cstring>

using namespace std;

const int MX = 10111;
int parent[MX], left[MX], right[MX], weight[MX], value[MX];

int rotate_right(int node)
{
    assert(left[node]);
    int then = left[node];
    // update center node
    parent[right[then]] = node;
    left[node] = right[then];
    // update then
    if (node == left[parent[node]])
	left[parent[node]] = then;
    else
	right[parent[node]] = then;
    parent[then] = parent[node];
    // update left child
    right[then] = node;
    parent[node] = then;
    
}

int rotate_left(int node)
{
    assert(left[node]);
    int then = left[node];
    // center
    parent[right[then]] = node;
    left[node] = right[then];
    // then
    if (left[parent[node]] == node)
	left[parent[node]] = then;
    else
	right[parent[node]] = then;
    parent[then] = parent[node];
    // root
    parent[node] = then;
    right[then] = node;

    return then;
}

void heapify_up(int node)
{
    if (!parent[node])
	return;
    if (weight[parent[node]] < weight[node])
	if (left[parent[node]] == node)
	    rotate_left(parent[node])
	else
	    rotate_right(parent[node])
    heapify_up(node);
}

void heapify_down(int node)
{
    if (!left[node] && !right[node])
	return;
    int then=0;
    if (left[node] && right[node])
	if (weight[left[node]] < weight[right[node]])
	    then = 1; 	// right
	else
	    then = -1;	// left
    else if (left[node] && weight[node] < weight[left[node]])
	then = -1;
    else if (right[node] && weight[node] < weight[right[node]])
	then = 1;

    if (then > 0)
	rotate_left(node);
    else if (then < 0)
	rotate_right(node);
    heapify_down(node);
}

// api
bool has(int num, int cur=1)
{
    if (num == cur)
	return true;

    if (num < cur)
	cur = left[cur];
    else if (num > cur)
	cur = right[cur];
    if (num == 0)
	return false;
    return has(cur);
}

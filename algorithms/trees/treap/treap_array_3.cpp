// 19 April 2020
// UNTESTED
#include <iostream>
#include <cstring>

using namespace std;

const int MX = 10111;
int root=1, parent[MX], left[MX], right[MX], weight[MX], value[MX];

int rotate_right(int node)
{
    assert(left[node]);
    int then = left[node];
    // update center node
    parent[right[then]] = node;
    left[node] = right[then];
    // update then
    if (!parent[node])
	root = then;
    else if (node == left[parent[node]])
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
    assert(right[node]);
    int then = right[node];
    // center
    parent[left[then]] = node;
    right[node] = left[then];
    // then
    if (!parent[node])
	root = then;
    else if (left[parent[node]] == node) // TODO: are these left/rights correct?
	left[parent[node]] = then;
    else
	right[parent[node]] = then;
    parent[then] = parent[node];
    // root
    parent[node] = then;
    left[then] = node;

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

void dump(int cur, int lay=0)
{ // in order
    dump(left[cur], lay+1);
    for (int i=0; i<lay; ++i) printf("    ");
    printf("(%d  %d)\n", value[cur], weight[cur]);
    dump(right[cur], lay+1);
}

// api
int find(int num, int cur=1)
{
    if (num == value[cur])
	return cur;

    if (num < value[cur])
	cur = left[cur];
    else if (num > value[cur])
	cur = right[cur];
    if (num == 0)
	return false;
    return has(num, cur);
}
// TODO: insert, delete, next, prev, dist

int main()
{
    while (true)
    {
	char c = '\n';
	while (c == '\n' || c == ' ')
	    scanf("%c", &c);
	
	int n;
	if (c == 'i')
	{
	    scanf("%d", &n)
	    printf("inserted to %d\n", insert(n));
	}
	else if (c == 'd')
	{
	    scanf("%d", &n);
	    printf("erase node %d: %d\n", n, erase(n));
	}
	else if (c == 'q')
	{
	    scanf("%d", &n);
	    printf("%d", find(n));
	}
	else if (c == 'n')
	{
	    scanf("%d", &n);
	    printf("after %d: %d", n, nxtt[n]);
	}
	else if (c == 'p')
	{
	    scanf("%d", &n);
	    printf("before %d: %d", n, pree[n]);
	}
	else if (c == 'd')
	{
	    int o;
	    scanf("%d%d", &n, &o);
	    printf("dist %d .. %d: %d\n", dist(n, o));
	}
	else if (c == 'm')
	{
	    dump(1);
	}
	else
	{
	    printf("unknown command! i d q n p d\n");
	}
    }
}


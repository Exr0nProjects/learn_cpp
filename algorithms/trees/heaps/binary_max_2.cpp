// 19 Apr 2020: TODO: SEGFAULTS

#include <iostream>

using namespace std;

const int MX = 10111;
int heap[MX], size=0;

bool cmp(int l, int r)
{ return l < r; }

void heapify_up(int node)
{
    if (node == 1) return;
    if (cmp(heap[node/2], heap[node]))
    {
	swap(heap[node/2], heap[node]);
	heapify_up(node/2);
    }
}

void heapify_down(int node)
{
    if (node*2 > size) return;
    int then = node*2;
    if (node*2+1 < size)
	if (cmp(heap[node*2], heap[node*2+1]))
	    then = node*2+1;
	else
	    then = node*2;

    if (cmp(heap[node], heap[then]))
	swap(heap[node], heap[then]);
    heapify_down(then);
}

void insert(int num)
{
    heap[++size] = num;
    heapify_up(size);
}

void pop()
{
    if (size == 0) return;
    swap(heap[1], heap[size--]);
    heapify_down(1);
}

int top()
{
    if (!size)
	printf("Heap is empty!\n");
    return heap[1];
}

int main()
{
    while (1)
    {
	int num;
	scanf("%d", &num);
	if (num == 0)
	    pop();
	else
	    insert(num);
	printf("max: %d\n", top());
    }
}

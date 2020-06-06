inline int lowbit(int t)
{
	return t & -t;
}

int query(int p)
{
	int ret = a[0];
	for (; p; p -= lowbit(p))
		ret += d[p];
	return ret;
}

void modify(int l, int r, int v)
{
	for (; l<=n; l+= lowbit(l))
		d[l] += v;
	for (++r; r<=n; r += lowbit(r))
		d[r] -= v;
}


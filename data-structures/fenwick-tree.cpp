//1-index
int ft[MAXN];

void update(int idx, int val) //updates positions >= idx
{
	while (idx <= n)
	{
		ft[idx] += val;
	   	idx += lsb(idx);	
	}
}

int query(int idx) //return prefix until idx
{
	int r = 0;
	while (idx > 0)
	{
		r += ft[idx];
		idx -= lsb(idx);
	}
	return r;
}

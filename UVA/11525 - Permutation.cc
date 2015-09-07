#include <cstdio>
#include <cstring>
#include <cstdlib>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

const int MAXN=50005;

int sum[MAXN*4];
int pos[MAXN];
int N;

void build(int rt, int l, int r)
{
	sum[rt]=r-l+1;
	if (l==r) return;
	build(lson, l, mid);
	build(rson, mid+1, r);
}

int query(int rt, int l, int r, int k)
{
	sum[rt]--;
	if (l==r) return l;
	if (k<=sum[lson]) return query(lson, l, mid, k);
	else return query(rson, mid+1, r, k-sum[lson]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		build(1, 1, N);
		for (int x, i=1; i<=N; i++)
		{
			scanf("%d", &x);
			pos[i]=query(1, 1, N, x+1);
		}
		for (int i=1; i<=N; i++)
		{
			printf("%d", pos[i]);
			if (i==N) printf("\n");
			else putchar(' ');
		}
	}
	return 0;
}

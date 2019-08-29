#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 5001
using namespace std;
struct Edge {
	int s, t, val;
}edge[N * 2];
int n, head[N], m, ma = 1 << 30, mi = 1, fa[N], S, T;
bool cmp(Edge A, Edge B) {
	return A.val < B.val;
}
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a == b)
		return a;
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}
int main() {
	freopen("Comf.in", "r", stdin);
	freopen("Comf.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].s, &edge[i].t, &edge[i].val);
	}
	scanf("%d%d", &S, &T);
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		int p = -1;
		for (int j = 1; j <= n; j++) {
			fa[j] = j;
		}
		for (int j = i; j <= m; j++) {
			int u = find(edge[j].s), v = find(edge[j].t);
			if (u != v) {
				fa[u] = v;
			}
			if (find(S) == find(T)) {
				p = j;
				break;
			}
		}
		if (p == -1)
			continue;
		if ((double)ma / (double)mi > (double)edge[p].val / double(edge[i].val))
			ma = edge[p].val, mi = edge[i].val;
	}
	if (ma == (1 << 30)) {
		printf("IMPOSSIBLE");
		return 0;
	}
	int g = gcd(ma, mi);
	mi /= g;
	ma /= g;
	if (mi == 1)
		printf("%d", ma);
	else
		printf("%d/%d", ma, mi);
	return 0;
}
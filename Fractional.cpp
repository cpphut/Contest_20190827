#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
struct p {
	int id, deg;
}f[10000];
bool cmp(p a, p b) {
	if (a.deg == b.deg) {
		return a.id < b.id;
	}
	return a.deg > b.deg;
}
int main() {
	freopen("Fractional.in", "r", stdin);
	freopen("Fractional.out", "w", stdout);
	scanf("%d%d", &n, &m);
	m *= 1.5;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &f[i].id, &f[i].deg);
	}
	sort(f + 1, f + 1 + n, cmp);
	int last = m + 1;
	while (f[m].deg == f[last].deg) {
		last++;
	}
	last--;
	printf("%d %d\n", f[last].deg, last);
	for (int i = 1; i <= last; i++) {
		printf("%d %d\n", f[i].id, f[i].deg);
	}
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10001];
int main()
{
	freopen("Martians.in", "r", stdin);
	freopen("Martians.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		next_permutation(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
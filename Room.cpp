#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 1000001
using namespace std;
int n, m;
struct cl {
	long long num;
	int s, t;
}a[N];
int cf[N];
int admit[N];
bool judge(int x) {
	memset(cf, 0, sizeof(cf));
	for (int i = 1; i <= x; i++) {
		cf[a[i].s] += a[i].num;
		cf[a[i].t + 1] -= a[i].num;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += cf[i];
		if (sum > admit[i])
			return false;
	}
	return true;
}
int main() {
	freopen("Room.in", "r", stdin);
	freopen("Room.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &admit[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld%d%d", &a[i].num, &a[i].s, &a[i].t);
	}
	if (judge(m)) {
		printf("0\n");
	}
	else {
		int left = 1, right = m;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (judge(mid))
				left = mid + 1;
			else
				right = mid;
		}
		printf("-1\n%d\n", left);
	}
	return 0;
}
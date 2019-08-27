#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n, a[5001], dp[5001], b[5001], ans, cnt;
int main() {
	freopen("Price.in", "r", stdin);
	freopen("Price.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] == 1) b[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j] && dp[i] == dp[j] + 1) {
				b[i] += b[j];
			}
			if (a[i] == a[j] && dp[i] == dp[j]) {
				b[j] = 0;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		if (dp[i] == ans) {
			cnt += b[i];
		}
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}
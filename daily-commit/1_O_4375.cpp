#include<bits/stdc++.h>
int n;
int main() {
	while (scanf("%d", &n) != EOF) {
		int cnt = 1, ret = 1;
		while (true) {
			if (cnt % n == 0) {
				printf("%d\n", ret);
				break;
			}
			else {
				cnt = (cnt%n * 10%n) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
	return 0;
}
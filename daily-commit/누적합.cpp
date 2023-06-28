//누적합 prefixsum
// 구간쿼리 팬익트리 psum
// 정적배열 누적합 , 동적 배열에는 팬익트리로 해야한다.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100004], b, c, psum[100004], n, m;
int main() {
	cout << "누적합x" << endl;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		int sum = 0;
		for (int j = b; j <= c; j++)sum += a[j];
		cout << sum << endl;
	}
	cout << "누적합 o" << endl;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		int sum = 0;
		sum = psum[c] - psum[b - 1];
		cout << sum << endl;
	}
	return 0;
}
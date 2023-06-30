#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, Max = -10000004, psum[100001],temp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> temp; psum[i] = psum[i - 1] + temp;
	}
	for (int i = k; i <= n; i++) {
		Max = max(Max, psum[i] - psum[i - k]);
	}
	cout << Max << endl;
	return 0;
}
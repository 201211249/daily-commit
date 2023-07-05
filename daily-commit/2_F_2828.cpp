#include<bits/stdc++.h>
using namespace std;
int n, m, j,ret,s,e,a;
int main() {
	cin >> n >> m;
	cin >> j;
	s = 1;
	for (int i = 0; i < j; i++) {
		e = s + m - 1;
		cin >> a;
		//바구니 위치에 떨어진다.
		if (a >= s && a <= e)continue;
		// 왼쪽으로 가야 한다.
		else {
			if (a < s) {
				ret += s - a;
				s = a;
			}
			else{
				a += (a - e);
				ret += a - e;
			}
		}
		
		// 오른쪽으로 가야한다.
	}
	cout << ret << "\n";
	return 0;
}
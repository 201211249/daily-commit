//시각은 이상 미만이다.
#include<bits/stdc++.h>
using namespace std;
int A, B, C, a[100], ret = 0, s, e;
int main() {
	
	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		cin >> s >> e;
		for (int j = s; j < e; j++) {
			a[j]++;
		}
	}
	for (int i = 1; i < 100; i++) {
		if (a[i] == 1)ret += A;
		else if (a[i] == 2)ret += B * 2;
		else if (a[i] == 3)ret += C * 3;
	}
	for (int i : a)cout << i << " ";
	cout << ret << endl;
	return 0;
}
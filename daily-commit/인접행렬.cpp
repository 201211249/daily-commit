#include<bits/stdc++.h>
using namespace std;
bool a[10][10];
int x, y, n;
// 방문안한 노드 찾기
// 연결된 노드를 이어서 방문하고 출력
// 방문했으면 다시 방문하지 않게 만들기 재귀함수로
bool check_a[10];
void go(int x) {
	check_a[x] = 1;
	cout << x << "\n";
	for (int i = 0; i < 10; i++) {
		if (check_a[i])continue;
		if (a[x][i])go(i);
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j])cout << i << ", " << j << "\n";
		}
	}
	cout << "2번 답" << "\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] == 1 && check_a[i] == 0)go(i);
		}
	}
	return 0;
}
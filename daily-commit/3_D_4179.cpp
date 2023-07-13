#include<bits/stdc++.h>
using namespace std;
int n, m, a[1004][1004], p[1004][1004], f[1004][1004], ret;
int dy[] = { -1, 0, 1,0 };
int dx[] = { 0, 1, 0,-1 };
char c;
int sy, sx, y, x;
int main() {
	queue<pair<int, int>> q;
	//fill(&f[0][0], &f[0][0] + 1004 * 1004, -1);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'F')f[i][j] = 1, q.push({ i,j });
			if (c == 'J')p[i][j] = 1, sy = i, sx = j;
			a[i][j] = c;
		}
	}
	while (!q.empty()) {
		tie(y, x) = q.front(), q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx >= m || nx < 0 || f[ny][nx])continue;
			if (a[ny][nx] == '#')continue;
			f[ny][nx] = f[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	y = 0; x = 0;
	q.push({ sy,sx });
	while (!q.empty()) {
		tie(y, x) = q.front(), q.pop();
		if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
			ret = p[y][x];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx >= m || nx < 0 || p[ny][nx])continue;
			if (a[ny][nx] == '#')continue;
			if (p[y][x] + 1 < f[ny][nx] || f[ny][nx] == 0) {
				p[ny][nx] = p[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
	if (ret != 0)cout << ret;
	else cout << "IMPOSSIBLE";
	return 0;
}
// 테두리로 검색한다.
// 치즈를 표시해야한다. (마지막 전을 표시하기 위해서)
// 테두리 치즈를 지운다. 
#include<bits/stdc++.h>
using namespace std;
int n, m,a[104][104],visited[104][104],cnt,cnth;
vector<pair<int, int>> chease,temp;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx < 0 || nx >= m)continue;
		if (visited[ny][nx])continue;
		if (a[ny][nx] == 1) {
			visited[ny][nx] = 1;
			chease.push_back({ ny, nx });
			continue;
		}
		dfs(ny, nx);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1)cnt++;
		}
	}
	while (1) {
		dfs(0, 0);
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		for (auto i : chease) {
			a[i.first][i.second] = 0;
		}
		cnt -= chease.size();
		cnth++;
		if (cnt <= 0)break;
		chease = temp;
	}
	cout << cnth << "\n";
	cout << chease.size() << "\n";
	return 0;
}
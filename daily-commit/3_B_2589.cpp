#include<bits/stdc++.h>
using namespace std;
int n, m, adj[54][54],visited[54][54],temp;
int dy[] = { -1,0,1,0 };
int dx[] = { 0, 1, 0, -1 };
string st;
vector<int> ret;
void bfs(int y, int x) {
	queue <pair<int, int>> s;
	s.push({ y,x });
	while (!s.empty()) {
		tie(y, x) = s.front(); s.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])continue;
			if (adj[ny][nx] == 'W')continue;
			visited[ny][nx] = visited[y][x] + 1;
			temp = max(temp, visited[ny][nx]);
			s.push({ ny,nx });
		}
	}
	ret.push_back(temp);
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> st;
		for (int j = 0; j < m; j++)adj[i][j] = st[j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (adj[i][j] == 'L') {
				visited[i][j] = 1;
				bfs(i, j);
				fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
			}
		}
	}
	sort(ret.begin(), ret.end());
	if (ret.size() == 0)cout << 0;
	else cout << ret[ret.size() - 1] - 1;
	return 0;
}
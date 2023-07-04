#include<bits/stdc++.h>
using namespace std;
int visited[104][104], n, m, s_y, s_x, e_y, e_x, k; // bfs 에서 방문했다는 것도 하고 최단거리도 담는배열이다.
vector<int> adj[104];
int x, y;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void bfs(int sy, int sx) {
	queue<pair<int,int>> q;
	visited[sy][sx] = 1;
	q.push({sy,sx});
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y +dy[i];
			int nx = x + dx[i];
			if (ny <0 || nx <0 || ny > n - 1 || nx > n - 1 || adj[ny][nx]==0)continue;
			if (visited[ny][nx])continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}
int main() {
	cin >> n >> m;
	cin >> s_y >> s_x;
	cin >> e_y >> e_x;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			cin >> k;
			temp.push_back(k);
		}
		adj[i] = temp;
	}
	bfs(s_y, s_x);
	cout << visited[e_y][e_x] << "\n";
	return 0;
}
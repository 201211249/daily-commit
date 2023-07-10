#include<bits/stdc++.h>
using namespace std;
int n, m, adj[10][10],visited[10][10], ret,cnt;
vector<pair<int, int>> virus_location, wall_location;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx < 0 || nx >= m || adj[ny][nx]==1)continue;
		if (visited[ny][nx])continue;
		dfs(ny, nx);
	}
	return;
}
int solve() {
	//memset(visited,0,sizeof(visited));
	cnt = 0;
	fill(&visited[0][0], &visited[0][0] +10 * 10, 0);
	for (int i = 0; i < virus_location.size(); i++) {
		dfs(virus_location[i].first, virus_location[i].second);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (adj[i][j] ==0 && !visited[i][j])cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj[i][j];
			if (adj[i][j] == 2)virus_location.push_back({ i,j });
			if (adj[i][j] == 0)wall_location.push_back({ i, j });
		}
	}
	for (int i = 0; i < wall_location.size(); i++) {
		for (int j = i + 1; j < wall_location.size(); j++) {
			for (int k = j + 1; k < wall_location.size(); k++) {
				adj[wall_location[i].first][wall_location[i].second] = 1;
				adj[wall_location[j].first][wall_location[j].second] = 1;
				adj[wall_location[k].first][wall_location[k].second] = 1;
				ret = max(ret, solve());
				adj[wall_location[i].first][wall_location[i].second] = 0;
				adj[wall_location[j].first][wall_location[j].second] = 0;
				adj[wall_location[k].first][wall_location[k].second] = 0;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}

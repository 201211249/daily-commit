#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1004];
int visited[1004];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int adj2[104][104];
int visited2[104][104];
int n, m, ret;
void dfs(int here) {
	visited[here] = 1;
	cout << here << " ";
	for (int there : adj[here]) {
		if (visited[there])continue;
		dfs(there);
	}
	return;
}
void dfs2(int here) {
	if (visited[here])return;
	visited[here] = 1;
	cout << here << " ";
	for (int there : adj[here]) {
		dfs2(there);
	}
}
void solve(int y, int x) {
	visited2[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > n - 1 || ny < 0 || nx <0 || nx >m - 1 || adj2[ny][nx]==0)continue;
		if (visited2[ny][nx])continue;
		solve(ny, nx);
	}
	return;
}
int main() {
	adj[1].push_back(2); 
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[4].push_back(2);
	adj[2].push_back(5);
	
	dfs(1); cout << "\n"; memset(visited, 0, sizeof(visited));
	dfs2(1); cout << "\n±ÙÇõÀÌ´ÂÆ®¸§ÀïÀÌ\n";
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adj2[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited2[i][j] || adj2[i][j]==0)continue;
			solve(i, j);
			ret++;
		}
	}
	cout << ret << "\n";
	return 0;
}
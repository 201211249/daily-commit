#include<bits/stdc++.h>
using namespace std;
int adj[101][101], visited[101][101], n, m, k, s_x, e_x, s_y, e_y, ret;
int dx[] = { 0,1,0,-1 }, dy[] = { -1,0,1,0 };
vector<int>result;
int  dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx < 0 || nx >= m)continue;
		if (visited[ny][nx] || adj[ny][nx] ==1)continue;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> s_x >> s_y >> e_x >> e_y;
		for (int x = s_x; x < e_x; x++) {
			for (int y = s_y; y < e_y; y++) {
				adj[y][x] = 1;
			}
		}
	}
	for (int i = n-1; i>=0; i--) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]==0 && adj[i][j]==0) {
				result.push_back(dfs(i,j));
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i : result)cout << i << " ";
	return 0;
}
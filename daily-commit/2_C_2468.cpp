#include<bits/stdc++.h>
using namespace std;
int adj[101][101], visited[101][101], N, ret,limit,cnt;
int dy[] = { -1, 0,1,0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x,int k) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= N || ny < 0 || nx >= N || nx < 0 )continue;
		if (visited[ny][nx] || adj[ny][nx]<=k)continue;
		dfs(ny, nx,k);
	}
	return;
}
int main() {
	//cout << ret << "\n";
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
			if (adj[i][j] > limit)limit = adj[i][j];
		}
	}
	for (int k = 0; k <= limit; k++) {
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && adj[i][j] > k) {
					dfs(i, j,k);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
		
	}
	cout << ret << "\n";
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//int adj[104][104],visited[104][104],n,m;
//int dy[] = { -1, 0, 1,0 };
//int dx[] = { 0, 1, 0, -1 };
//void bfs(int y, int x) {
//	visited[y][x] = 1;
//	queue<pair<int, int>> q;
//	q.push({ y, x });
//	while (q.size()) {
//		tie(y, x) = q.front(); q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (ny >= n || ny < 0 || nx >= m || nx < 0 || adj[ny][nx] == 0)continue;
//			if (visited[ny][nx])continue;
//			visited[ny][nx] = visited[y][x] + 1;
//			q.push({ ny, nx });
//		}
//	}
//	return;
//}
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int N , M;
//	cin >> n >> m;
//	N = n - 1; 
//	M = m - 1;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		for (int j = 0; j < m; j++) {
//			adj[i][j] = s[j] - '0';
//		}
//	}
//	bfs(0, 0);
//	cout << visited[N][M] << "\n";
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//int n, l, r,a[54][54],visited[54][54],cnt,ret;
//int dy[] = { -1, 0, 1, 0 };
//int dx[] = { 0, 1,0, -1 };
//vector<pair<int, int>>v;
//void bfs(int y, int x) {
//	queue<pair<int, int>> q;
//	q.push({ y,x });
//	while (!q.empty()) {
//		tie(y, x) = q.front(); q.pop();
//		for (int i = 0; i < 4; i++) {
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])continue;
//			if (abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r) {
//				visited[ny][nx] = 1;
//				v.push_back({ny,nx});
//				q.push({ ny,nx });
//				cnt++;
//			}
//		}
//	}
//	return;
//}
//void change_people() {
//	int sum = 0;
//	for (int i = 0; i < v.size(); i++) {
//		sum += a[v[i].first][v[i].second];
//	}
//	for (int i = 0; i < v.size(); i++) {
//		a[v[i].first][v[i].second] = sum / v.size();
//	}
//	return;
//}
//int main() {
//	cin >> n >> l >> r;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> a[i][j];
//		}
//	}
//
//	while (true) {
//		cnt = 0;
//		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (visited[i][j])continue;
//				else {
//					v.clear();
//					visited[i][j] = 1;
//					v.push_back({ i,j });
//					bfs(i, j);
//					change_people();
//					//cnt++;
//				}
//			}
//		}
//		if (cnt == 0)break;
//		else ret++;
//	}
//	cout << ret;
//	return  0;
//}

#include<bits/stdc++.h>
using namespace std;
int n, l, r,a[54][54],visited[54][54],cnt,ret,sum;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1,0, -1 };
vector<pair<int, int>>v;
void dfs(int y, int x) {
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])continue;
			if (abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r) {
				visited[ny][nx] = 1;
				v.push_back({ny,nx});
				sum += a[ny][nx];
				dfs(ny, nx);
			}
		}
	return;
}
void change_people() {
	cnt = 1;
	for (int i = 0; i < v.size(); i++) {
		a[v[i].first][v[i].second] = sum / v.size();
	}
	return;
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j])continue;
				else {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j });
					sum = a[i][j];
					dfs(i, j);
					if (v.size() == 1)continue;
					change_people();
				}
			}
		}
		if (cnt == 0)break;
		ret++;
	}
	cout << ret;
	return  0;
}
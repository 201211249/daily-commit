#include<bits/stdc++.h>
using namespace std;
int num, a[3], visited[64][64][64];
vector<int>b = { 9,3,1 };
vector<vector<int>> v;
struct A {
	int y, x, z;
};
queue<A> q;
int bfs(int y, int x, int z) {
	visited[y][x][z] = 1;
	q.push({ y,x,z });
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		z = q.front().z;
		q.pop();
		if (visited[0][0][0])break;
		for (int i = 0; i < v.size(); i++) {
			int ny = max(y -v[i][0],0);
			int nx = max(x - v[i][1],0);
			int nz = max(z - v[i][2],0);
			if (visited[ny][nx][nz])continue;
			visited[ny][nx][nz] = visited[y][x][z] + 1;
			q.push({ ny,nx,nz });
		}
	}
	return visited[0][0][0]-1;
}
int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}
	sort(b.begin(), b.end());
	do {
		v.push_back(b);
	} while (next_permutation(b.begin(), b.end()));
	cout <<bfs(a[0],a[1],a[2]);
	return 0;
}
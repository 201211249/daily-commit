#include<bits/stdc++.h>
using namespace std;
vector<int> adj[10];
vector<int> v;
int visited[10];
int mp[3][3] = { {10, 20 ,21},{70, 90, 12},{80, 110, 120} },visited_mp[3][3];
int dy[] = { -1 ,0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
void dfs(int y, int x) {
	if (y == 2 && x == 2) {
		for (int i : v)cout << i << " ";
		cout << "\n";
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3 || visited_mp[ny][nx])continue;
		visited_mp[ny][nx] = 1;
		v.push_back(mp[ny][nx]);
		dfs(ny, nx);
		visited_mp[ny][nx] = 0;
		v.pop_back();
	}
	return;
}
void print() {
	for (int i : v) {
		cout << (char)(i + 'A') << " ";
	}
	cout << "\n";
	return;
}
void go(int idx) {
	if (v.size() == 3) {
		print();
		return;
	}
	for (int there : adj[idx]) {
		if (visited[there])continue;
		visited[there] = 1;
		v.push_back(there);
		go(there);
		visited[there] = 0;
		v.pop_back();
	}
}

int main() {
	adj[0].push_back(1);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(3);
	adj[3].push_back(1);
	visited[0] = 1;
	v.push_back(0);
	go(0);
	//±àÁ¤¿Õ È«Ã¶ÀÌÀÇ ±¸°É ¿©Çà
	v.clear();
	visited_mp[0][0] = 1;
	v.push_back(mp[0][0]);
	dfs(0, 0);
	return 0;
}
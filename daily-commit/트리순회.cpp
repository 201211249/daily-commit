#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1004];
int visited[1004];
void postOder(int here) {
	if (visited[here])return;
	if (adj[here].size() == 1)postOder(adj[here][0]);
	if (adj[here].size() == 2) {
		postOder(adj[here][0]);
		postOder(adj[here][1]);
	}
	visited[here] = 1;
	cout << here << " ";
	return;
}
void preOder(int here) {
	if (visited[here])return;
	visited[here] = 1;
	cout << here << " ";
	if (adj[here].size() == 1)preOder(adj[here][0]);
	if (adj[here].size() == 2) {
		preOder(adj[here][0]);
		preOder(adj[here][1]);
	}
	return;
}
void inOder(int here) {
	if (visited[here])return;
	if (adj[here].size() == 1) {
		inOder(adj[here][0]);
		visited[here] = 1;
		cout << here << " ";
	}
	if (adj[here].size() == 2) {
		inOder(adj[here][0]);
		visited[here] = 1;
		cout << here << " ";
		inOder(adj[here][1]);
	}
	if (adj[here].size() == 0) {
		visited[here] = 1;
		cout << here << " ";
	}
	return;
}
void bfs(int here) {
	queue<int> q;
	q.push(here);
	while (q.size()) {
		int here = q.front(); q.pop();
		cout << here << " ";
		for (int there : adj[here]) {
			if (visited[there])continue;
			q.push(there);
		}
	}
}
int main() {
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	int root = 1;
	cout << "postOder" << "\n";
	postOder(root); memset(visited, 0, sizeof(visited));
	cout << "\npreOder" << "\n";
	preOder(root); memset(visited, 0, sizeof(visited));
	cout << "\ninOder" << "\n";
	inOder(root); memset(visited, 0, sizeof(visited));
	cout << "\n레벨별 순회 bfs\n";
	bfs(root); memset(visited, 0, sizeof(visited));
	return 0;
}
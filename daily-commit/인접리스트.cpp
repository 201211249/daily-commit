#include<bits/stdc++.h>
using namespace std;
const int V = 10;
int n, x, y, visited[V];
vector<int> adj[V];
void go(int from) {
	visited[from] = 1;
	cout << from << "\n";
	for (auto i : adj[from]) {
		if (visited[i])continue;
		go(i);
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < V; i++) {
		if (adj[i].size() == 0)continue;
		if (visited[i] == 0)go(i);
	}
	return 0;
}
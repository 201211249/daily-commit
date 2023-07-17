#include<bits/stdc++.h>
using namespace std;
const int mx = 100000;
int n, k,visited[mx + 1],cnt[mx + 1];
void bfs() {
	queue<int> q;
	q.push(n);
	cnt[n] = 1;
	visited[n] = 1;
	while (!q.empty()) {
		int num = q.front(); q.pop();
		for (int next : {num - 1, num + 1, num * 2}) {
			if (next <0 || next >mx)continue;
			if (visited[next]) {
				if (visited[next] == visited[num] + 1)cnt[next] += cnt[num];
				continue;
			}
			q.push(next);
			visited[next] = visited[num] + 1;
			cnt[next] += cnt[num];
		}
	}
	return;
}
int main() {
	cin >> n >> k;
	if (n == k) {
		cout << 0 << "\n";
		cout << 1 << "\n";
		return 0;
	}
	bfs();
	cout << to_string(visited[k] - 1) << "\n";
	cout << to_string(cnt[k]) << "\n";
	return 0;
}
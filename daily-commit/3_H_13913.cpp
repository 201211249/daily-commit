#include<bits/stdc++.h>
using namespace std;
//#define next aaaa
const int Max = 200000;
int n, k;
pair<int,int> visited[Max + 1];
vector<int> ret;
int main() {
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	visited[n] = { 1,n };
	while (!q.empty()) {
		int num = q.front(); q.pop();
		if (num == k)break;
		for (int next : {num - 1, num + 1, num * 2}) {
			if (next<0 || next >=Max)continue;
			if (visited[next].first)continue;
			visited[next] = { visited[num].first + 1, num };
			q.push(next);
		}
	}
	cout << visited[k].first - 1 << "\n";
	ret.push_back(k);
	while (k != n) {
		ret.push_back(visited[k].second);
		k = visited[k].second;
	}
	reverse(ret.begin(), ret.end());
	for (int i : ret)cout << i << " ";
	return 0;
}

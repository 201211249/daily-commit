//#include<bits/stdc++.h>
//using namespace std;
//vector<int>trust[10001];
//int n, m, a, b, visited[10001],mx;
////pair<int, vector<int>> Max;
//int dp[10004];
//int dfs(int here) {
//	visited[here] = 1;
//	int cnt = 1;
//	for (int there : trust[here]) {
//		if (visited[there])continue;
//		cnt += dfs(there);
//		//child++;
//	}
//	//if (child == 0)return 1;
//	return cnt;
//}
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> a >> b;
//		trust[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++) {
//		fill(&visited[0], &visited[0] + 10001, 0);
//		dp[i] = dfs(i);
//		mx = max(dp[i], mx);
//		/*if (Max.first < temp) {
//			Max.first = temp;
//			Max.second.clear();
//			Max.second.push_back(i);
//		}
//		else if (Max.first == temp)Max.second.push_back(i);*/
//	}
//	//sort(Max.second.begin(), Max.second.end());
//	for (int i = 1; i <= n; i++) {
//		if (mx == dp[i])cout << i << " ";
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int dp[10001], mx, visited[10001], n, m, a, b;

int dfs(int here) {
	visited[here] = 1;
	int ret = 1;
	for (int there : v[here]) {
		if (visited[there]) continue;
		ret += dfs(there);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		mx = max(dp[i], mx);
	}
	for (int i = 1; i <= n; i++) if (mx == dp[i]) cout << i << " ";
	return 0;
}
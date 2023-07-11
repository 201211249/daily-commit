//#include<bits/stdc++.h>
//using namespace std;
//int t[51][51], visited[51], n, p, root, d, cnt;
//void delete_node(int d) {
//	for (int i = 0; i < n; i++) if (t[d][i] == 1) t[d][i] = 0, t[i][d] = 0;
//	return;
//}
//void dfs(int p) {
//	visited[p] = 1;
//	int cntl = 0;
//	for (int i = 0; i < n; i++) {
//		if (t[p][i] && !visited[i])dfs(i), cntl++;
//	}
//	if (cntl == 0)cnt++;
//	return;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> p;
//		if (p == -1)root = i;
//		else t[p][i] = 1, t[i][p]=1;
//	}
//	cin >> d;
//	if (d == root)cout << 0 << "\n";
//	else {
//		delete_node(d);
//		dfs(root);
//		cout << cnt << "\n";
//	}
//	
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n, temp, root,d;
vector<int>t[54];
int dfs(int a) {
	int ret = 0, child = 0;
	if (a == d)return ret;
	for (auto i : t[a]) {
		if (i == d)continue;
		ret += dfs(i);
		child++;
	}
	if (child == 0)return 1;
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) root = i;
		else t[temp].push_back(i);
	}
	cin >> d;
	cout << dfs(root) << "\n";
	return 0;
}
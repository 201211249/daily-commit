#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char adj[65][65];
int n;
string result,s;
string dfs(int y, int x, int size) {
	if (size == 1)return string(1, adj[y][x]);
	string ret = "";
	char b = adj[y][x];
	for (int i = y; i< y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (b != adj[i][j]) {
				ret += '(';
				ret += dfs(y, x, size / 2);
				ret += dfs(y, x + size / 2, size / 2);
				ret += dfs(y + size / 2, x, size / 2);
				ret += dfs(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, adj[y][x]);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			adj[i][j] = s[j];
		}
	}
	cout << dfs(0, 0, n) << "\n";
	//cout << ret << "\n";
	return 0;
}
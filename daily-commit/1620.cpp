#include<bits/stdc++.h>
using namespace std;
int n, m;
string s, a[100004];
map<string, int> mp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <=n; i++) {
		cin >> s;
		a[i] = s;
		mp[s] = i ;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (atoi(s.c_str()) == 0) cout << mp[s] << "\n";
		else cout << a[atoi(s.c_str())] << "\n";
	}
	return 0;
}
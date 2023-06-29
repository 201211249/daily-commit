#include<bits/stdc++.h>
using namespace std;
string s, ret;
int n, cnt[26];
map<char, int> mp;
int main() {
	// map 으로
	cout << "map으로" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (mp[s[0]])mp[s[0]]++;
		else mp[s[0]]++;
	}
	for (auto i : mp)if (i.second >= 5)ret += i.first;
	if (ret.size())cout << ret << endl;
	else cout << "PREDAJA" << endl;
	ret = "";
	// 배열로
	cout << "배열로" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cnt[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++)if (cnt[i] >= 5)ret += i + 'a';
	if (ret.size())cout << ret << endl;
	else cout << "PREDAJA" << endl;
	return 0;
}
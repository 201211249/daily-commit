#include<bits/stdc++.h>
using namespace std;
string s, ret;
int cnt[25], flag;
char mid,temp;
int main() {
	cin >> s;
	for (char i : s)cnt[i - 'A']++;
	for (int i = 25; i >= 0; i--) {
		if (cnt[i] == 0)continue;
		temp = i + 'A';
		if (cnt[i]%2 ==1) {
			mid = temp; flag++;
			cnt[i]--;
		}
		if (flag == 2)break;
		for (int j = 0; j < cnt[i]; j += 2) {
			ret = temp + ret;
			ret += temp;
		}
	}
	if (mid)ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)cout << "I'm Sorry Hansoo" << "\n";
	else cout << ret << "\n";
	return 0;
}
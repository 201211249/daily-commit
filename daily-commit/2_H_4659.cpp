#include<bits/stdc++.h>
using namespace std;
int ccnt, vcnt;
string s;
bool is_vowel(int a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')return true;
	return false;
}
int main() {
	while (1) {
		cin >> s; if (s == "end")break;
		int prev = -1;
		bool flag = 0;
		bool include_vowel = 0;
		ccnt = vcnt = 0;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i];
			if (is_vowel(idx))vcnt++, ccnt = 0, include_vowel = 1;
			else ccnt++, vcnt = 0;
			if (ccnt == 3 || vcnt == 3)flag = 1;
			if (i >= 1 && prev == idx && idx != 'e' && idx != 'o')flag = 1;
			prev = idx;
		}
		if (include_vowel == 0) flag = 1;
		if (flag)cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}
	return 0;
}
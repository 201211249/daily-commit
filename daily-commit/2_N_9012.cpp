#include<bits/stdc++.h>
using namespace std;
int t;
string s;
bool check_stack(string a) {
	stack<char> c;
	for (char i : a) {
		if (i == '(')c.push(i);
		else if (!c.empty()) c.pop();
		else return false;
	}
	return c.empty();
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> s;
		if (check_stack(s))cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
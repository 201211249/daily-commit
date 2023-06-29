#include<bits/stdc++.h>
using namespace std;
int main() {
	string s,temp;
	cin >> s;
	temp = s;
	reverse(s.begin(), s.end());
	if (s == temp)cout << 1 << endl;
	else cout <<0 <<endl;
	return 0;
}
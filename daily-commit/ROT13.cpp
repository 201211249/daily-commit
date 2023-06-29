#include<bits/stdc++.h>
using namespace std;
string s;
void ROT13(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 97 && s[i]<=122) {
			if (s[i] - 'a' + 13 > 25)s[i] = s[i] + 13 - 26;
			else s[i] = s[i] + 13;
		}
		else if(s[i] >= 65 && s[i] <=90){
			if (s[i] - 'A' + 13 > 25)s[i] = s[i] + 13 - 26;
			else s[i] = s[i] + 13;
		}
	}
	cout << s << endl;
	return ;
}
int main() {
	getline(cin, s);
	ROT13(s);
	return 0;
}
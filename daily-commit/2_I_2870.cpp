//#include<bits/stdc++.h>
//using namespace std;
//vector<string> ret;
//int n;
//string s;
//bool is_num(char c) {
//	return (c - '0' >= 0 && c - '0' <= 9);
//}
//string delete_zero(string s) {
//	for (int i = 0; i < s.size(); i++) {
//		if (s[i] != '0')return s.substr(i);
//	}
//	return "0";
//}
//void find_num(string s) {
//	int prev = -1;
//	string temp = "";
//	for (int i = 0; i < s.size(); i++) {
//		if (is_num(s[i])) {
//			temp += s[i];
//		}
//		else {
//			if (i >= 1 && is_num(s[prev]))ret.push_back(delete_zero(temp)), temp = "";
//		}
//		prev = i;
//	}
//	if (temp.size())ret.push_back(delete_zero(temp));
//	return;
//}
//bool cmp(string a, string b) {
//	if (a.size() == b.size())return a < b;
//	return a.size() < b.size();
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> s;
//		find_num(s);
//	}
//	sort(ret.begin(), ret.end(), cmp);
//	for (auto i : ret)cout << i << "\n";
//
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n;
string s,temp;
vector<string> ret;
void make_num(string temp){
	while (1) {
		if (s.size() && s.front() == '0')s.erase(s.begin());
		else break;
	}
	if (s.size())ret.push_back(s);
	else ret.push_back("0");
	temp = "";
	return;
}
bool cmp(string a, string b) {
	if (a.size() == b.size())return a < b;
	return a.size() < b.size();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < 65)temp += s[j];
			else if (temp.size())make_num(temp);
		}
		if (temp.size())make_num(temp);
	}
	sort(ret.begin(), ret.end(), cmp);
	for (auto i : ret)cout << i << "\n";
	return 0;
}
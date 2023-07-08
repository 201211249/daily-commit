//#include<bits/stdc++.h>
//using namespace std;
//int n, team, prev_n, cnt[3],cntg[3];
//string s, prev_t;
//int make_second(string m) {
//	return stoi(m.substr(0,m.find(":"))) * 60 + stoi(m.substr(m.find(":")+1));
//}
//string make_min(int s) {
//	int Min = s / 60;
//	string m,sec;
//	int second = s % 60;
//	if (Min < 10) m = "0" + to_string(Min);
//	else m = to_string(Min);
//	if (second < 10) sec = "0" + to_string(second);
//	else sec = to_string(second);
//	return m+":"+sec;
//}
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> team >> s;
//		if (prev_n == 0) {
//			prev_n = team;
//			prev_t = s;
//			cntg[team]++;
//			continue;
//		}
//		cntg[team]++;
//		if (cntg[1] == cntg[2]) {
//			cnt[prev_n] += make_second(s)- make_second(prev_t);
//			prev_n = 0, prev_t = "";
//		}
//	}
//	if (prev_n != 0) cnt[prev_n] += make_second("48:00") - make_second(prev_t);
//
//	cout << make_min(cnt[1]) << "\n";
//	cout << make_min(cnt[2]) << "\n";
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define prev kss
int cnt1, cnt2, n,sum1,sum2,team;
string s,prev;
int make_second(string t) {
	return atoi(t.substr(0,2).c_str())*60 + atoi(t.substr(3,2).c_str());
}
void make_sum(int& sum, string a) {
	sum += make_second(a) - make_second(prev);
}
void print(int a) {
	string Min = "00" + to_string(a / 60);
	string second = "00" + to_string(a % 60);
	cout << Min.substr(Min.size() - 2, 2) + ":" + second.substr(second.size() - 2, 2) << "\n";
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> team >> s;
		if (cnt1 > cnt2)make_sum(sum1,s);
		else if (cnt2 > cnt1)make_sum(sum2,s);
		team == 1 ? cnt1++ : cnt2++;
		prev = s;
	}
	if (cnt1 > cnt2)make_sum(sum1, "48:00");
	else if (cnt2 > cnt1)make_sum(sum2, "48:00");
	print(sum1);
	print(sum2);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,ret;
vector<int> v;
bool check(int num) {
	if (num == 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)return false;
	}
	return true;
}
void go2(int idx, int sum) {
	if (ret % 11 == 10) return; // 백트래킹
	if (idx == v.size()) {
		ret = max(ret, sum % 11);
		cnt++;
		return;
	}
	go2(idx + 1, sum + v[idx]);
	go2(idx + 1, sum);
	return;
}
void go(int idx, int sum) {
	if (idx == v.size()) {
		if (check(sum))cnt++;
		return;
	}
	go(idx + 1, sum + v[idx]);
	go(idx + 1,sum);
	return;
}
int main() {
	// for문을 이용한 완전탐색
	v = { 1,2,3,4,5 };
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 5) {
			cout << i << "\n";
			break;
		}
	}
	// while문을 이용한 완탐
	int i = 0;
	while (i < v.size()) {
		if (v[i] == 5) {
			cout << i << "\n";
			break;
		}
		i++;
	}
	// 랄로의 2400 찾기
	cin >> n;
	string s;
	i = 2400;
	cnt = 0;
	while (true) {
		s = to_string(i);
		if (s.find("2400") != string::npos) cnt++;
		if (n == cnt)break;
		i++;
	}
	cout << s << "\n";
	// 재귀함수를 활용한 완탐(만약 반복문으로 된다면 반복문으로 해결) 
	// why? 함수호출이 코스트가 더 크다
	// 조합 순열 dfs bfs
	// 경우의 수 마다 생각해야 하는 로직도 나온다
	// 조합 만들고 그 합이 소수인 전체 경우의수
	cin >> n;
	v.clear();
	cnt = 0;
	while (n > 0) {
		cin >> k;
		v.push_back(k);
		n--;
	}
	go(0, 0);
	cout << cnt << "\n";
	// 조합 만들고 그 합이 mod 11 했을 때 나오는 가장 큰수를 구하여라
	cin >> n;
	cnt = 0;
	v.clear();
	while (n > 0) {
		cin >> k;
		v.push_back(k);
		n--;
	}
	go2(0, 0);
	cout << ret << "\n";
	cout << cnt << "\n";
	return 0;
}

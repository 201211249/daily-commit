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
	if (ret % 11 == 10) return; // ��Ʈ��ŷ
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
	// for���� �̿��� ����Ž��
	v = { 1,2,3,4,5 };
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 5) {
			cout << i << "\n";
			break;
		}
	}
	// while���� �̿��� ��Ž
	int i = 0;
	while (i < v.size()) {
		if (v[i] == 5) {
			cout << i << "\n";
			break;
		}
		i++;
	}
	// ������ 2400 ã��
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
	// ����Լ��� Ȱ���� ��Ž(���� �ݺ������� �ȴٸ� �ݺ������� �ذ�) 
	// why? �Լ�ȣ���� �ڽ�Ʈ�� �� ũ��
	// ���� ���� dfs bfs
	// ����� �� ���� �����ؾ� �ϴ� ������ ���´�
	// ���� ����� �� ���� �Ҽ��� ��ü ����Ǽ�
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
	// ���� ����� �� ���� mod 11 ���� �� ������ ���� ū���� ���Ͽ���
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

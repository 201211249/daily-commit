#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> hs,ck;
int n, m,temp,d,ret = pow(50,4);
vector<vector<int>> combi_ck;
vector<int> v;
int distance(pair<int, int> h, pair<int, int> c) {
	int a = abs(h.first - c.first);
	int b = abs(h.second - c.second);
	return a + b;
}
//int cal() {
//	int sum = 0;
//	for (int i = 0; i < hs.size(); i++) {
//		d = 0;
//		for (int j = 0; j < v.size(); j++) {
//			if (d == 0)d = distance(hs[i], ck[v[j]]);
//			else d = min(d, distance(hs[i], ck[v[j]]));
//		}
//		sum += d;
//	}
//	return sum;
//}
void combi(int idx) {
	if (m == v.size()) {
		// 도시의 치킨거리 
		combi_ck.push_back(v);
		return;
	}
	for (int i = idx + 1; i < ck.size(); i++) {
		v.push_back(i);
		combi(i);
		v.pop_back();
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1)hs.push_back({ i,j });
			else if (temp == 2)ck.push_back({ i,j });
		}
	}
	combi(-1);
	for (vector<int> cList : combi_ck) {
		int sum = 0;
		for (pair<int, int> home : hs) {
			d = 0;
			for (int ch : cList) {
				if (d == 0)d = distance(home, ck[ch]);
				else d = min(d, distance(home, ck[ch]));
			}
			sum += d;
		}
		ret = min(ret, sum);
	}
	cout << ret << "\n";
	return 0;
}
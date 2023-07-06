//#include<bits/stdc++.h>
//using namespace std;
//int n, c, k;
//vector<int>temp, ret, cnt;
//bool compare(int x, int y) {
//	int id_x = find(temp.begin(), temp.end(), x) - temp.begin();
//	int id_y = find(temp.begin(), temp.end(), y) - temp.begin();
//	if (cnt[id_x] == cnt[id_y]) return id_x < id_y;
//	return cnt[id_x] > cnt[id_y];
//}
//int main() {
//	cin >> n >> c;
//	for (int i = 0; i < n; i++) {
//		cin >> k;
//		if (find(ret.begin(), ret.end(),k) != ret.end()) {
//			cnt[find(ret.begin(), ret.end(), k) - ret.begin()]++;
//		}
//		else {
//			ret.push_back(k);
//			cnt.push_back(1);
//		}
//	}
//	temp = ret;
//	sort(ret.begin(), ret.end(), compare);
//	for (int i = 0; i < ret.size(); i++) {
//		for (int j = 0; j < cnt[find(temp.begin(), temp.end(), ret[i])-temp.begin()]; j++) {
//			cout << ret[i] << " ";
//		}
//	}
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n, a[1004], c;
map<int, int> mp, mp_idx;
vector<pair<int, int>> v;
bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second == y.second)return mp_idx[x.first] < mp_idx[y.first];
	return x.first > y.first;
}
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; mp[a[i]]++;
		if (mp_idx[a[i]] == 0) {
			mp_idx[a[i]] = i + 1;
		}
	}
	for (auto i : mp) {
		v.push_back({ i.second,i.first });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first; j++) {
			cout << v[i].second << " ";
		}
	}
	return 0;
}
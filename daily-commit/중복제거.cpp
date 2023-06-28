// 중복제거는 2가지 있다.
// map
// cnt 배열, unique() 함수
#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;

int main() {
	vector<int> v{1, 1, 2, 2, 3, 3, 1, 1,2, 4,4};
	for (int i : v) {
		if (mp[i]) continue;
		else mp[i] = 1;
	}
	vector<int> ret;
	for (auto it : mp) ret.push_back(it.first);
	for (int i : ret) cout << i << " ";
	cout << endl;
	for (int i : v)cout << i << " ";
	cout << endl;
	auto it = unique(v.begin(), v.end());
	for (int i : v)cout << i << " ";
	cout << endl;
	cout << it - v.begin() << endl;
	for (int i : v)cout << i << " ";
	cout << endl;
	sort(v.begin(), v.end());
	for (int i : v)cout << i << " ";
	cout << endl;
	unique(v.begin(), v.end());
	for (int i : v)cout << i << " ";
	cout << endl;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i : v)cout << i << " ";
	cout << endl;
	return 0;
}

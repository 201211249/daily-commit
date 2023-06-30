// 백설공주가 집에 오니까 아홉명이서 내가 진짜 일곱난쟁이다 이지랄 하는거임
// 2명은 가짜야 근혁이가 심어놓은 가짜다
// 내기억에 일곱난쟁이녀석의 키의 합이 딱 100이였던게 기억이나는거야 
// 자 이제 누가 가짜일까?
#include<bits/stdc++.h>
using namespace std;

int a[9], sum;
vector<int> v;
pair<int, int> ret;
//void solve() {
//	
//	for (int i = 0; i < 9; i++) {
//		for (int j = i + 1; j < 9; j++) {
//			if (sum - a[i] - a[j] == 100) {
//				ret = { a[i],a[j]};
//				return;
//			}
//		}
//	}
//}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << "순열로 푼다." << endl;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	sort(a, a + 9);
	do {
		sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += a[i];
		}
		if (sum == 100)break;
	} while (next_permutation(a, a + 9));
	for (int i = 0; i<7; i++) cout << a[i] << endl;
	/*sum = 0;
	cout << "조합으로 푼다." << endl;
	for (int i = 0; i < 9; i++) {
		cin >> a[i]; sum += a[i];
	}
	solve();
	for (int i : a) {
		if (ret.first == i || ret.second == i)continue;
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	for (int i : v)cout << i << endl;*/
	return 0;
}
// �鼳���ְ� ���� ���ϱ� ��ȩ���̼� ���� ��¥ �ϰ������̴� ������ �ϴ°���
// 2���� ��¥�� �����̰� �ɾ���� ��¥��
// ����￡ �ϰ������̳༮�� Ű�� ���� �� 100�̿����� ����̳��°ž� 
// �� ���� ���� ��¥�ϱ�?
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
	cout << "������ Ǭ��." << endl;
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
	cout << "�������� Ǭ��." << endl;
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
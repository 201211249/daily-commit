#include<bits/stdc++.h>
using namespace std;
int n, m, j,ret,s,e,a;
int main() {
	cin >> n >> m;
	cin >> j;
	s = 1;
	for (int i = 0; i < j; i++) {
		e = s + m - 1;
		cin >> a;
		//�ٱ��� ��ġ�� ��������.
		if (a >= s && a <= e)continue;
		// �������� ���� �Ѵ�.
		else {
			if (a < s) {
				ret += s - a;
				s = a;
			}
			else{
				a += (a - e);
				ret += a - e;
			}
		}
		
		// ���������� �����Ѵ�.
	}
	cout << ret << "\n";
	return 0;
}
// ����
// �ּ��� �ް� �����ϸ� ����.
// ������ Ǫ�� ���.
// 1. ������ ���ϴ�.
// 2. ������ �ؼ��մϴ�.
// 3. �ڵ带 �ۼ��մϴ�.

#include<iostream>
using namespace std;
string dopa = "abcde";
// ����
// 1. 3�����
// 2. �Ųٷ� ���
// 3. ���ؽ� �߰� ���

int main() {
	// 3�����
	cout << dopa.substr(0, 3) << endl;
	// �Ųٷ� ���
	reverse(dopa.begin(), dopa.end());
	cout << dopa << endl;
	// ���ؽ� �߰� ���
	cout << dopa + "���ؽ�" << endl;
	return 0;
}
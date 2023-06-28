// ���� ����ִ� -> ����
// ���� ������� -> ����
// �������� ������ ���ġ�Ͽ� ... ~�� ������ ��� max ���� >> ����


#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void printV(vector<int>& V) {
	for (int i = 0; i < V.size()-1; i++) {
		cout << V[i] << " ";
	}
	cout << endl;
}

void makePermutation(int n, int r, int depth) {
	cout << n << " : " << r << " : " << depth << endl;
	if (r == depth) {
		// logic
		printV(v);
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
		
	}
	return;
}


int main() {
	int a[3] = { 1, 2, 3 };
	
	for (int i = 0; i < 3; i++)v.push_back(a[i]);
	makePermutation(3, 3, 0);
	cout << "=======================" << endl;
	v.clear();
	for (int i = 2; i >= 0; i--)v.push_back(a[i]);
	do {
		printV(v);
	} while (prev_permutation(v.begin(), v.end()));
	cout << endl << "���ĵǾ����� ���� �迭���" << endl;
	int b[] = { 1, 3, 2 };
	do {
		for (int i : b)cout << i << " ";
		cout << endl;
	} while (next_permutation(b, b + 3));
	cout << "���ĵ� �迭���" << endl;
	sort(b, b + 3);
	do {
		for (int i : b)cout << i << " ";
		cout << endl;
	} while (next_permutation(b, b + 3));
	return 0;
}
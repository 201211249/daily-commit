#include<bits/stdc++.h>
using namespace std;
int n = 5;
int k = 3;
int a[] = { 1, 2, 3, 4, 5 };

void printV(vector<int> &v) {
	for (int i : v) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void combi(int start, vector<int>&v) {
	if (v.size() == k) {
		printV(v);
	}
	for (int i = start + 1; i < n; i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}
int main() {
	vector<int> v;
	combi(-1, v);
	cout << "ÁßÃ¸for¹®" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				cout << a[k] << " " << a[j] << " " << a[i] << endl;
			}
		}
	}
	return 0;
}
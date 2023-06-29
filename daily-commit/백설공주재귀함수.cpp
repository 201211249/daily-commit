#include<bits/stdc++.h>
using namespace std;

int a[9];
int sum;
int n = 9, r = 7;
void solve() {
	 sum = 0;
	 for (int i = 0; i < 7; i++) {
		 sum += a[i];
	 }
	 if (sum == 100) {
		 sort(a, a + 7);
		 for (int i = 0; i < 7; i++)cout << a[i] << endl;
		 exit(0);
	 }
}
void printA() {
	for (int i = 0; i < r; i++)cout << a[i] << " ";
	cout << endl;
	return;
}

void makePermutation(int n, int r, int depth) {
	if (r == depth) {
		solve();
		//printA();
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(a[i], a[depth]);
		makePermutation(n, r, depth+1);
		swap(a[i], a[depth]);
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	makePermutation(n, r, 0);
	return 0;
}
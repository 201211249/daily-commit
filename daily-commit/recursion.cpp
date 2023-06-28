#include<bits/stdc++.h>
using namespace std;

// 재귀함수
// 1. 함수를 다시 부른다.
// 2. for 문으로 한다.

// Factorial of a Number n! = n * (n-1)*(n-2)*... *1
// 함수 재호출
int fact_rec(int n) {
	if (n == 0 || n == 1) return 1;
	return n * fact_rec(n - 1);
}
// for 문으로
int fact_for(int n) {
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		ret *= i;
	}
	return ret;
}
// 피보나치 수 Fn F0 = 0 F1 = 1 Fn = Fn-1 + Fn-2
int fibo(int n) {
	if (n == 1 || n == 0)return n;
	return fibo(n - 1) + fibo(n - 2);
}

int n = 5;

int main() {
	cout << fact_rec(n) << endl;
	cout << fact_for(n) << endl;
	cout << fibo(n) << endl;
	return 0;
	// 120 120 
}

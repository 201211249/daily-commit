#include<bits/stdc++.h>
using namespace std;

// 재귀함수
// 재귀함수는 정의 단계에서 자신을 재참조하는 함수
// 전달되는 상태인 매개변수가 달라질 뿐 똑같은 일을 하는 함수
// 큰 문제를 작은 부분문제로 나눠서 풀 때 사용한다.
// 반드시 기저사례를 써야 한다.(종료조건)
// 사이클이 있다면 쓰면 안된다. ex) f(a)가 f(b)를 호출한 뒤 f(b)가 다시 f(a)를 호출
// 반복문으로 될 거같으면 반복문으로 (함수호출에 대한 코스트)

// Factorial of a Number n! = n * (n-1)*(n-2)*... *1
// 함수 재호출
int fact_rec(int n) {
	if (n == 1 || n == 0)return 1;
	return n * fact_rec(n - 1);
}
// for 문으로
int fact_for(int n) {
	int ret = 1;
	for (int i = 2; i <= n; i++) {
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
	// 120 120 5
}

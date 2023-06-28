// 구현
// 주석을 달고 구현하면 좋다.
// 문제를 푸는 방법.
// 1. 문제를 봅니다.
// 2. 문제를 해석합니다.
// 3. 코드를 작성합니다.

#include<iostream>
using namespace std;
string dopa = "abcde";
// 문제
// 1. 3개출력
// 2. 거꾸로 출력
// 3. 엄준식 추가 출력

int main() {
	// 3개출력
	cout << dopa.substr(0, 3) << endl;
	// 거꾸로 출력
	reverse(dopa.begin(), dopa.end());
	cout << dopa << endl;
	// 엄준식 추가 출력
	cout << dopa + "엄준식" << endl;
	return 0;
}
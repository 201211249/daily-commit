#include<bits/stdc++.h>
using namespace std;
int n, ret= -2147483648;
char c;
vector<int> num;
string total_oper;
int oper(int a, int b, char c) {
	if (c == '+')return a + b;
	else if (c == '*')return a * b;
	else return a - b;
}
void go(int idx, int _num) {
	if (idx == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}
	go(idx + 1, oper(_num, num[idx + 1], total_oper[idx]));
	if (idx + 2 <= num.size()-1) {
		int temp = oper(num[idx + 1], num[idx + 2], total_oper[idx + 1]);
		go(idx + 2, oper(_num,temp,total_oper[idx]));
	}
	return;
}
int main() {
	//ret = (int)((pow(2, 31)-1)*(-1));
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == '*' || c == '+' || c == '-')total_oper += c;
		else num.push_back(stoi(string(1, c)));
	}
	go(0, num[0]);
	cout << ret;
	return 0;
}
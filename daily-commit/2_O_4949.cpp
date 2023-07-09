//#include<bits/stdc++.h>
//using namespace std;
//string s;
//bool check(string a) {
//	stack<char> ret;
//	for (char c : a) {
//		if (c != '(' && c != ')' && c != '[' && c != ']')continue;
//		else {
//			if (ret.empty()) {
//				if (c == ')' || c == ']')return false;
//				else ret.push(c);
//			}
//			else {
//				if (ret.top() == '(') {
//					if (c == ')')ret.pop();
//					else {
//						if (c == ']')return false;
//						else ret.push(c);
//					}
//				}
//				else {
//					if (c == ']')ret.pop();
//					else {
//						if (c == ')')return false;
//						else ret.push(c);
//					}
//				}
//			}
//		}
//	}
//	return ret.empty();
//}
//int main() {
//	while (1) {
//		getline(cin, s);
//		if (s == ".")break;
//		if (check(s))cout << "yes" << "\n";
//		else cout <<"no" << "\n";
//	}
//	return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//string s;
//bool check(string a) {
//	stack<char> ret;
//	for (char c : a) {
//		if (c == ')') {
//			if (ret.size() == 0 || ret.top() == '[')return false;
//			else ret.pop();
//		}
//		else if (c == ']') {
//			if (ret.size() == 0 || ret.top() == '(')return false;
//			else ret.pop();
//		}
//		if (c == '(')ret.push(c);
//		if (c == '[')ret.push(c);
//	}
//	return ret.empty();
//}
//int main() {
//	while (1) {
//		getline(cin, s);
//		if (s == ".")break;
//		if (check(s))cout << "yes" << "\n";
//		else cout << "no" << "\n";
//	}
//	return 0;
//}
#include <bits/stdc++.h> 
using namespace std;
int main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    while (true) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        stack<int> stk;
        bool check = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                if (stk.size() == 0 || stk.top() == '[') {
                    check = false;
                    break;
                }
                else {
                    stk.pop();
                }
            }
            if (s[i] == ']') {
                if (stk.size() == 0 || stk.top() == '(') {
                    check = false;
                    break;
                }
                else {
                    stk.pop();
                }
            }
            if (s[i] == '(') stk.push(s[i]);
            if (s[i] == '[') stk.push(s[i]);
        }
        if (check && stk.size() == 0)  cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
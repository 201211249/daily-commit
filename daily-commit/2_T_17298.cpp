//#include<bits/stdc++.h>
//using namespace std;
//stack<pair<int,int>> st;
//int ret[1000001];
//int n, k;
//int main() {
//	cin >> n;
//	memset(ret, -1, sizeof(ret));
//	for (int i = 0; i < n; i++) {
//		cin >> k;
//		while (!st.empty() && st.top().second < k) {
//			ret[st.top().first] = k;
//			st.pop();
//		}
//		st.push({ i,k });
//	}
//	for (int i = 0; i < n; i++)cout << ret[i] << " ";
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int ret[1000001],n ,a[1000001];
int main() {
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (!st.empty() && a[st.top()] < a[i]) {
			ret[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++)cout << ret[i] << " ";
	return 0;
}
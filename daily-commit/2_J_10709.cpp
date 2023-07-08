#include<bits/stdc++.h>
using namespace std;
int h, w, flag, idx_c;
vector<int> temp,ret;
string s;
int main() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s;
		flag = 0;
		ret = temp;
		for (int j = 0; j < w; j++) {
			if(s[j]=='c'){
				cout << 0 << " ";
				if (flag) {
					idx_c = j;
				}
				else {
					idx_c = j;
					flag = 1;
				}
			}
			else {
				if (flag) {
					cout << j - idx_c << " ";
				}
				else cout << -1 << " ";
			}
		}
		cout << "\n";
		/*for (auto k : ret)cout << k << " ";
		cout << "\n";*/
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//int h, w, ret[104][104],cnt;
//string s;
//int main() {
//	cin >> h >> w;
//	for (int i = 0; i < h; i++) {
//		cin >> s;
//		for (int j = 0; j < w; j++) {
//			if (s[j] == 'c')ret[i][j] = 0;
//			else ret[i][j] = -1;
//		}
//	}
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (ret[i][j] == 0) {
//				cnt = 1;
//				while (ret[i][j + 1] == -1) {
//					ret[i][j + 1] = cnt++;
//					j++;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) cout << ret[i][j] << " ";
//		cout << "\n";
//	}
//	return 0;
//}
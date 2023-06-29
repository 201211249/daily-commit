// 카운팅 스타 ~ 맵또는배열~~~
// 맵은 스트링 기반
// 배열은 인티저 기반 ex) 요소 자체가 1000만 정도면 ... 공간 할당이 안됨 띄엄띄엄 오면
// 문자를 카운팅


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
int cnt[26];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (char a : str) {
		cnt[a - 'a']++;
	}
	for (int i = 0; i < 26; i++)cout << cnt[i] << " ";

	return 0;
}
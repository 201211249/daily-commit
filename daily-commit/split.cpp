#include<bits/stdc++.h>
using namespace std;

vector<string> split(string input, string d) {
	vector<string>ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(d)) != string::npos) {
		token = input.substr(0, pos);
		if (token != "")ret.push_back(token);
		input.erase(0, pos+d.length());
	}
	if (input != "")ret.push_back(input);
	return ret;
}

int main() {
	string s = "abcffabcffabcff", d = "f";
	vector<string> a = split(s, d);
	for (string i : a)cout << i << endl;
	cout << a.size();
	return 0;
}
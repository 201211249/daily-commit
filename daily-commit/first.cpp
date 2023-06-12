#include <string>
#include <vector>
#include<iostream>
#include<cstdlib>
using namespace std;

string solution(string s) {
    string answer = "";
    string check = "";
    int max = 0;
    int min = 0;
    int cnt = 0;
    bool first = true;
    
    while (cnt <= s.length()) {
        if (s[cnt] != ' ') {
            check += s[cnt];
            
        }
        else {
            if (first) {
                max = stoi(check);
                min = stoi(check);
                first = false;
                check = "";
            }
            else {
                if (max < stoi(check))max = stoi(check);
                if (min > stoi(check))min = stoi(check);
                check = "";
            }
        }
        if (cnt == s.length()) {
            if (max < stoi(check))max = stoi(check);
            if (min > stoi(check))min = stoi(check);
            check = "";
        }
        cnt++;
    }
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    return answer;
}
int main() {
    cout << solution("-1 4") << endl;
    
    return 0;
}
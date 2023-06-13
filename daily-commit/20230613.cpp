#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

string solution(string input_string) {
    string answer = "";
    bool check = false;
    for (int i = 0; i < input_string.length() - 1; i++) {
        char out = input_string[i];
        if (answer.find(out) != string::npos)continue;
        for (int j = i + 1; j < input_string.length(); j++) {
            if (out != input_string[j] && !check) {
                check = true;
                continue;
            }
            if (out == input_string[j] && check) {
                answer += out;
                check = false;
                break;
            }
            if (j == input_string.length() - 1)check = false;
        }
    }
    sort(answer.begin(), answer.end());
    if (answer == "")return "N";
    return answer;
}

int main() {
    cout << solution("aaabaaa") << endl;
    return 0;
}
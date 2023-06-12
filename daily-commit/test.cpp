#include <string>
#include <vector>
#include <iostream>

using namespace std;
int find_idx(string answer, char idx) {
    for (int i = 0; i < 8; i++) {
        if (answer[i] == idx) {
            return i;
        }
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RTCFJMAN";
    string a;
    vector<int> point_box(8, 0);
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4)continue;
        else if (choices[i] > 4) {
            point_box[find_idx(answer, survey[i][1])] += choices[i] - 4;
        }
        else {
            if (choices[i] == 1) {
                point_box[find_idx(answer, survey[i][0])] += 3;
            }
            else if (choices[i] == 3) {
                point_box[find_idx(answer, survey[i][0])] += 1;
            }
            else {
                point_box[find_idx(answer, survey[i][0])] += 2;
            }
        }
    }
    for (int i = 0; i < point_box.size(); i += 2) {
        if (point_box[i] < point_box[i + 1]) {
            a.push_back(answer[i + 1]);
        }
        else {
            a.push_back(answer[i]);
        }

    }

    return a;
}

int main() {
    cout << solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 }) << endl;
    cout << solution({"TR", "RT", "TR"}, {7, 1, 3}) << endl;
    cout << "¹Ùº¸" << endl;
    return 0;
}
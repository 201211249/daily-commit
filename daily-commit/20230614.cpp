#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> t_idx;
int Max = 0;

void dfs(vector<vector<int>> ability, int y, int result) {
    if (t_idx.size() == ability[0].size()) {
        if (Max < result) {
            Max = result;
        }
        return;
    }
    for (int i = 0; i < ability.size(); i++) {
        if (find(t_idx.begin(), t_idx.end(), i) == t_idx.end()) {
            t_idx.push_back(i);
            dfs(ability, y + 1, result + ability[i][y]);
            t_idx.erase(t_idx.end() - 1);
        }
    }
}

int solution(vector<vector<int>> ability) {
    int answer = 0;

    dfs(ability, 0, 0);

    return Max;
}
//
//int main() {
//    cout << solution({ {40, 10, 10} ,{20, 5, 0},{30, 30, 30},{70, 0, 70},{100, 100, 100} })<< endl;
//
//    return 0;
//}
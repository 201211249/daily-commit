#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int h = 3;
    for (int i = h; i < sum; i++) {
        if (sum % i == 0) {
            int w = sum / i;
            if ((w - 2) * (i - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}
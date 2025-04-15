#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (auto i : A) {
        auto iter = upper_bound(B.begin(), B.end(), i);
        if (iter == B.end())break;
        *iter = -1;
        answer++;
    }
    return answer;
}
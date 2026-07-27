#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.push_back(-1);
    for (int i = 1; i < s.size(); i++)
    {
        auto pos = s.rfind(s[i], i - 1);
        if (pos != -1)
            answer.push_back(i - pos);
        else
            answer.push_back(-1);
    }
    return answer;
}
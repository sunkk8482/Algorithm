#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size(),0);
    unordered_map<string, int> um;
    for (int i = 0; i < name.size(); i++)
    {
        um[name[i]] = yearning[i];
    }
    for (int i = 0; i < photo.size(); i++)
    {
        for (auto j : photo[i])
        {
            answer[i] += um[j];
        }
    }

    return answer;
}
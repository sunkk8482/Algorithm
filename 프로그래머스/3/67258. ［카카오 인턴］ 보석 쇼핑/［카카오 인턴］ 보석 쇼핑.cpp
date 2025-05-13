#include <string>
#include <vector>
#include <unordered_map>    

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 보석의 종류 확인
    unordered_map<string, int> um;
    for (auto i : gems) {
        um[i] = 0;
    }
    // 현재 몇종류가 들어가 있는지 확인하는 변수
    int now = 0;
    
    // 투포인터로 계산
    int start = 0;
    int end = 0;
    int size = gems.size();
    answer.push_back(999999);
    answer.push_back(2134567890);
    
    for (int i = 0; i < gems.size(); i++) {
        if (um[gems[i]] == 0)now++;
        um[gems[i]]++;
        if (now == um.size()) {
            int temp = start;
            for (int j = start; j <= i; j++) {
                if (um[gems[j]] == 1) {
                    temp = j;
                    um[gems[j]]--;
                    now--;
                    break;
                }
                um[gems[j]]--;
            }
            int now_diff = i - temp;
            int answer_diff = answer[1] - answer[0];
            if (answer_diff > now_diff) {
                answer[1] = i;
                answer[0] = temp;
            }
            else if (answer_diff == now_diff) {
                if (answer[0] > temp) {
                    answer[1] = i;
                    answer[0] = temp;
                }
            }
            start = temp + 1;
        }
        
    }

    answer[0]++;
    answer[1]++;
    return answer;
}

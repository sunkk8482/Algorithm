#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;

    for (auto i : operations) {
        string oper = i.substr(0, 1);
        int num = stoi(i.substr(2, i.size()));
        if (oper == "I") {
            v.push_back(num);
        }
        else if (oper == "D") {
            if (v.size() == 0)continue;
            if (num == 1) {
                sort(v.begin(), v.end());
                v.pop_back();
            }
            else if (num == -1) {
                sort(v.begin(), v.end(), greater<int>());
                v.pop_back();
            }
        }
    }
    if (v.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else    if (v.size() == 1) {
        answer.push_back(v[0]);
        answer.push_back(v[0]);
    }
    else {
        sort(v.begin(), v.end());
        answer.push_back(v[v.size()-1]);
        answer.push_back(v[0]);
    }

    return answer;
}

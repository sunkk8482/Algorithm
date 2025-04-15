#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int start;
    int end;
};

bool compare(node left, node right) {
    if (left.end < right.end) {
        return true;
    }
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<node> v;
    for (auto i : routes) {
        v.push_back({ i[0],i[1] });
    }
    sort(v.begin(), v.end(), compare);
    int nowend = -30001;
    for (auto i : v) {
        if (i.start > nowend) {
            answer++;
            nowend = i.end;
        }
    }
    return answer;
}
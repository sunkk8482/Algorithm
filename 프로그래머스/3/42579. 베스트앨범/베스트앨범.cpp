#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    int play;
    int num;
};
struct sec {
    int total=0;
    vector<node> v;
};
bool compare(node left, node right) {
    if (left.play > right.play) {
        return true;
    }
    else if (left.play == right.play) {
        if (left.num < right.num) {
            return true;
        }
    }
    return false;
}


unordered_map<string, sec> um;
priority_queue<sec> pq;

bool operator<(sec left, sec right) {
    if (left.total > right.total) {
        return false;
    }
    return true;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    
    for (int i = 0; i < genres.size(); i++) {
        um[genres[i]].v.push_back({ plays[i],i });
        um[genres[i]].total += plays[i];
    }

    for (auto i : um) {
        pq.push(i.second);
    }

    while (!pq.empty()) {
        sec now = pq.top();
        pq.pop();
        vector<node> no = now.v;
        sort(no.begin(), no.end(), compare);
        if (no.size() >= 2) {
            answer.push_back(no[0].num);
            answer.push_back(no[1].num);
        }
        else if (no.size() == 1)
        {
            answer.push_back(no[0].num);
        }
    }
    
    return answer;
}
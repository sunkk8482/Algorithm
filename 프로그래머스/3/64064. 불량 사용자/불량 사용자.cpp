#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct node
{
    set<int> se;
    int index;
};

int calc(vector<vector<int>> v) {
    queue<node> q;
    set<int> st;
    q.push({ st,0 });
    while (!q.empty()) {
        node now = q.front();
        if (now.index == v.size())break;

        q.pop();
        for (auto i : v[now.index]) {
            set<int> temp;
            temp = now.se;
            temp.insert(i);
            if (temp.size() == now.se.size())continue;
            q.push({ temp,now.index + 1 });
        }
    }
    set<set<int>> test;
    while (!q.empty()) {
        node now = q.front();
        test.insert(now.se);
        q.pop();
    }
    return test.size();
}

bool match(string banned, string user) {
    if (banned.size() != user.size())return false;
    for (int i = 0; i < banned.size(); i++) {
        if (banned[i] == '*')continue;
        if (banned[i] != user[i])return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> v(banned_id.size(), vector<int>());
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (match(banned_id[i], user_id[j])) {
                v[i].push_back(j);
            }
        }
    }
    answer= calc(v);
    return answer;
}
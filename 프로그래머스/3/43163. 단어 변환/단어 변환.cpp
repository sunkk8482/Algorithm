#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> graph(51, vector<int>(51, 0));
int visited[51];

void dfs(int idx, string target,vector<string> words,int depth,int& ans) {

    if (words[idx] == target) {
        if(depth<ans) ans = depth;
        return;
    }
    for (int i = 0; i < words.size();i++) {
        if (visited[i])continue;
        if (!graph[idx][i])continue;
        visited[i] = 1;
        dfs(i, target,words,depth+1,ans);
        visited[i] = 0;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 101010;
    int startIdx = 0;
    words.push_back(begin);
    int size = words.size();
    int length = words[0].size();
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            int dif = 0;
            for (int k = 0; k < length; k++) {
                if (words[i].at(k) != words[j].at(k)) {
                    dif++;
                }
            }
            if (dif <= 1) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    for (auto i : words) {
        if (i == begin) {
            break;
        }
        startIdx++;
    }
    
    dfs(startIdx, target, words, 0, answer);
    if (answer == 101010)answer = 0;

    return answer;
}
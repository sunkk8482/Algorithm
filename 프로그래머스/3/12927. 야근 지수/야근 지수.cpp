#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(auto i : works) {
        pq.push(i);
    }

    while (n && !pq.empty()) {
        int now = pq.top();
        pq.pop();
        now--;
        if (now != 0) {
            pq.push(now);
        }
        n--;
    }

    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }

    return answer;
}
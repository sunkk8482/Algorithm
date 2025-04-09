#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 0;
    int right = 200000000;
    while (left <= right) {
        int mid = (left + right) / 2;
        bool avail = true;
        int cnt = 0;
        for (auto i : stones) {
            if (i<mid) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt >= k) {
                avail = false;
                break;
            }
        }
        if (avail) {
            answer = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer;
}
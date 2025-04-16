#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int now = 1;
	int range = w * 2 + 1;
	for (auto i : stations) {
		int left = i - w;
		int right = i + w;
		if (left <= now) {
			now = right + 1;
			continue;
		}
		int remain = left - now;
		int quo = remain / range;
		answer += quo;
		if(remain%range!=0)answer += 1;
		now = right + 1;
	}
	if (now <= n) {
		int remain = n - now;
		int quo = remain / range;
		answer += quo+1;
	}
	return answer;
}
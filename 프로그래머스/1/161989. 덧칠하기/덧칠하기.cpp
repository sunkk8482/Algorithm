#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int start = 0;
	int cnt = 0;
	for (int i = 0; i < section.size(); i++) {
		int now = section[i];
		if ((start + m - 1) < now||start==0)
		{
			start = now;
			cnt++;
		}

	}
	return cnt;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1010][1010];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int iStartIndex = triangle.size();
	int line = 1;

	for (auto i : triangle) {
		int index = iStartIndex;
		for (auto j : i) {
			arr[line][index] = max(arr[line - 1][index - 1], arr[line - 1][index + 1]) + j;
			if (line == triangle.size()) {
				answer = max(answer, arr[line][index]);
			}
			index += 2;
		}
		line++;
		iStartIndex--;
	}
	return answer;
}
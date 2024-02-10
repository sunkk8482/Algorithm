#include<iostream>

using namespace std;

int main() {
	int cnt = 0;
	int answer;
	cin >> answer;
	int x = 64;
	while (x >answer) {
		x = x >> 1;
	}
	int num = x;
	while (num != answer) {
		x = x >> 1;
		if (x + num <= answer) {
			num = num+ x;
			cnt++;
		}
	}
	cout << cnt+1;
}
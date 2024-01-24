#include<iostream>
#include <cstring>
using namespace std;

int co[15];
int N;
int res = 0;

bool check(int q) {
	for (int i = 0; i < q; i++) {
		if (co[i] == co[q] || (q - i == abs(co[q] - co[i]))) {
			return false;
		}
	}
	return true;
}
void fun(int level) {
	if (level == N) {
		res += 1;
		return;
	}
	for (int i = 0; i < N; i++) {
		co[level ] = i;
		if (check(level)) {
			fun(level+1);
		}
	}
}

int main() {
	cin >> N;
	fun(0);
	cout << res;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

char arr[3] = { '+',' ','-'};

int answer=0;

vector<string> answers;

int get_result(string s) {
	int number[10] = {};
	char arr[10] = {};
	
	int num_idx = 0;
	int arr_idx = 0;

	bool is_num = false;

	int get_num = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) <= '9' && s.at(i) >= '0') {
			if (!is_num) {
				get_num = 0;
				get_num += s.at(i) - '0';
				is_num = true;
			}
			else {
				get_num *= 10;
				get_num += s.at(i) - '0';
			}
		}
		else if (s.at(i) == ' ') {
			continue;
		}
		else {
			is_num = false;
			number[num_idx] = get_num;
			num_idx++;
			arr[arr_idx] = s.at(i);
			arr_idx++;
		}
	}
	number[num_idx] = get_num;
	int ret = number[0];
	
	for (int i = 0; i < arr_idx ;i++) {
		if (arr[i] == '+') {
			ret += number[i + 1];
		}
		else {
			ret -= number[i + 1];
		}
	}
	return ret;

}
//N : 지금 숫자 , s 수식, result 결과, fin 끝 수
void func(int N,string s,int fin) {
	if (N == fin) {
		int result = get_result(s);
		if (result == 0) {
			answers.push_back(s);
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			string next = s;
			next += '+';
			next += to_string(N + 1);
			func(N + 1, next, fin);
		}
		else if (i == 2) {
			string next = s;
			next += '-';
			next += to_string(N + 1);
			func(N + 1, next, fin);
		}
		else if (i == 1) {
			string next = s;
			next += ' ';
			next += to_string(N + 1);
			func(N + 1, next, fin);
		}
	}
}

void solve() {
	int N;
	cin >> N;
	string s = "";
	s += to_string(1);
	func(1,s,N);
	sort(answers.begin(),answers.end());
	for (auto i : answers) {
		cout << i << "\n";
	}

	cout << "\n";
	answers.clear();
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}
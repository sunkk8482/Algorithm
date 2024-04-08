#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;

struct node {
	string s;
	int length;
	int index;
};

struct alpha {
	int index;
	int priority;
};

int dat[26];

int priority[26];

bool compare(node left, node right) {
	if (left.length > right.length)return true;
	else if (left.length == right.length) {
		for (int i = 0; i < left.length;i++) {
			if (priority[left.s.at(i)-'A'] > priority[right.s.at(i) - 'A']) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}
bool compare_a(alpha left, alpha right) {
	if (left.priority > right.priority) {
		return true;
	}
	return false;
}

int main() {
	memset(dat, -1, sizeof(int) * 26);
	vector<node> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		int size = input.size();
		v.push_back({ input,size,0 });
	}
	for (int i = 0; i < v.size(); i++) {
		string now = v[i].s;
		int multi = 1;
		for (int j = 0; j < v[i].length; j++) {
			multi *= 10;
		}
		for (int j = 0; j < v[i].length; j++) {
			priority[now.at(j) - 'A'] += multi;
			multi /= 10;
		}
	}

	vector<alpha> va;

	for (int i = 0; i < 26; i++) {
		va.push_back({ i,priority[i] });
	}

	sort(va.begin(), va.end(), compare_a);
	
	int number = 9;
	for (int i = 0; i < va.size(); i++) {
		dat[va[i].index] = number--;
	}

	vector<int> numbers;
	for (auto i : v) {
		int number = 0;
		for (int j = 0; j < i.length; j++) {
			number *= 10;
			number += dat[i.s[j] - 'A'];
		}
		numbers.push_back(number);
	}
	int answer = 0;
	for (auto i : numbers) {
		answer += i;
	}
	cout << answer;
}


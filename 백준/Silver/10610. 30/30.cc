#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string s;
vector<int> v;
int N, sum;

int main()
{
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i] - '0');
		sum += v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	if (v[v.size() - 1] == 0 && sum % 3 == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
	else {
		cout << -1;
	}
}
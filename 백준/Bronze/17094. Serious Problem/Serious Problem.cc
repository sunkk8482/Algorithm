#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	string s;
	cin >> s;

	int ecnt = 0;
	int scnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '2') {
			ecnt++;
		}
		else {
			scnt++;
		}
	}

	if (ecnt > scnt) {
		cout << '2';
	}
	else if(ecnt==scnt){
		cout << "yee";
	}
	else {
		cout << "e";
	}

}
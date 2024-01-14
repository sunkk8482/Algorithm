#include <iostream>
#include <string>
using namespace std;

char stack[1001];
int top = 0;

void push(char a) {
	top++;
	stack[top] = a;
}

char pop() {
	char ret = stack[top--];
	return ret;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();
	string s;
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		int size = s.size();
		for (int i = 0; i < size; i++) {
			if (s.at(i) != 32 && i!=size-1) {
				push(s.at(i));
			} else if (i==size-1){
				cout << s.at(i);
				while (top != 0) {
					char a = pop();
					cout << a;
				}
			}
			else {
				while (top != 0) {
					char a =  pop();
					cout << a;
				}
				cout << " ";
			}
		}
		cout << endl;
	}

}

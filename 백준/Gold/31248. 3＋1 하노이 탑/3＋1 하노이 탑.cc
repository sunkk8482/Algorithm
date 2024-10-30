#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<char, char>P;
int moveCount = 0;
vector<P> v;

void move(char start, char end) {
    v.push_back(P(start, end));
    moveCount++;
}

void hanoi(int n, char now, char next, char tmp) {
    if (n == 1) {
        move(now, next);
        return;
    }
    hanoi(n - 1, now, tmp, next);
    move(now, next);
    hanoi(n - 1, tmp, next, now);
}

void modHanoi(int n, char now, char next, char tail, char dest) {
    if (n == 1) {
        move(now, dest);
        return;
    }
    else if(n == 2){
        move(now, next);
        move(now, dest);
        move(next, dest);
        return;
    }
    hanoi(n - 2, now, next, tail);
    move(now, tail);
    move(now, dest);
    move(tail, dest);
    modHanoi(n - 2, next, now, tail, dest);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    modHanoi(N, 'A', 'B', 'C', 'D');
    cout << moveCount << "\n";
    for (P p : v) {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
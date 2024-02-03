#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int A, B;

struct node {
    long long num;
    int level;
};
queue<node> q;

int main() {
    cin >> A >> B;
    node input{ A,0 };

    int answer = -1;
    q.push(input);
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        if (now.num == B) {
            answer=now.level+1;
            break;
        }
        if (now.num * 2 <= B) {
            q.push({ now.num * 2,now.level + 1 });
        }
        if ((now.num * 10)+1 <= B) {
            q.push({( now.num * 10) + 1,now.level + 1 });
        }


    }

    cout << answer;
    return 0;
}

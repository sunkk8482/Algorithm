#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int pass)
{
    if (n == 1)
        printf("%d %d\n", from, to);
    else
    {
        hanoi(n - 1, from, pass, to);
        printf("%d %d\n", from, to);
        hanoi(n - 1, pass, to, from);
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1 << num) - 1 << "\n";
    hanoi(num, 1, 3, 2);
}
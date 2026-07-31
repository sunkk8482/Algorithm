#include <string>
#include <vector>

using namespace std;

vector<int> cnts(100001, 0);

void calc()
{
    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i)
            cnts[j]++;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    calc();
    for (int i = 1; i <= number; i++)
        answer += (cnts[i] > limit) ? power : cnts[i];
    return answer;
}
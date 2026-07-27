#include <string>
#include <vector>

using namespace std;

int factor(int n)
{
    int num = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (i*i == n) {
            num++;
        }
        else if (n % i)
        {
            num += 2;
        }
    }
    return num;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        if (factor(i) % 2 == 0) {
            answer += i;
        }
        else {
            answer -= i;
        }
    }
    return answer;
}
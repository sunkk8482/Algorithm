#include <string>
#include <vector>

using namespace std;

int fun(int n)
{
    int sum = 0;
    if (n == 0)
    {
        return 0;
    }

    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            sum += i;
        }
        else if(n % i == 0)
        {
            sum += i;
            sum += (n / i);
        }
    }
    return sum;
}

int solution(int n) {
    int answer = fun(n);
    return answer;
}
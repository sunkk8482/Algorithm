#include <string>
#include <vector>

using namespace std;

int arr[1000001];

int solution(int n) {
    int answer = 0;

    for (int i = 1; i < 1000001; i++)
    {
        for (int j = i; j < 1000001; j += i)
        {
            arr[j]++;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i]==2)
        {
            answer++;
        }
    }
    return answer;
}
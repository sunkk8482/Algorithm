using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = 0;
    for (int i = 1; i <= count; i++)
    {
        sum += price * i;       
    }
    if (money >= sum)
    {
        return 0;
    }
    else
    {
        return sum - money;
    }
}
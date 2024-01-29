#include<iostream>
 
using namespace std;
 
long long arr[200];
    long long sum[200] ;

int gcd(int x, int y)
{
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}
 
int main()
{
    int t, n;
  
 
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        for (int k = 0; k < n; k++)
        {
            for (int p = k + 1; p < n; p++)
            {
                sum[i] += gcd(arr[k], arr[p]);
            }
        }
    }
 
    for (int i = 0; i < t; i++)
    {
        cout << sum[i]<<"\n";
    }
}
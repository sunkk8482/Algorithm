#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(int a, int b) {
    unordered_map<int, int> m;
    m[0] = 0; 
    m[1] = 31; m[2] = 29; m[3] = 31; m[4] = 30; m[5] = 31;
    m[6] = 30; m[7] = 31; m[8] = 31; m[9] = 30; m[10] = 31;
    m[11] = 30; m[12] = 31;

    unordered_map<int, string> day;
    day[1] = "FRI"; day[2] = "SAT"; day[3] = "SUN";
    day[4] = "MON"; day[5] = "TUE"; day[6] = "WED"; day[0] = "THU";

    int currentDay = 0;  

    for (int i = 0; i < a; i++) {
        currentDay += m[i];
        
        // 현재 월의 일(b일)을 더함
        if (a - 1 == i)
            currentDay += b;
    }

    return day[currentDay % 7];
}
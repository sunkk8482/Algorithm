#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if ((int)s[i] + n > (int)'z')
            {
                s[i] = 'a'+((int)s[i] + n) - 'z' - 1;
            }
            else
            {
                s[i] += n;
            }
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if ((int)s[i] + n > (int)'Z')
            {
                s[i] = 'A' + ((int)s[i] + n) - 'Z' - 1;
            }
            else
            {
                s[i] += n;
            }
        }
    }
    return s;
}
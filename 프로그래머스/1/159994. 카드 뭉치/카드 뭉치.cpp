#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	for (auto i : goal)
	{
		if (cards1.size() > 0 && cards1[0] == i)
		{
			cards1.erase(cards1.begin());
			continue;
		}
		else if (cards2.size() > 0 && cards2[0] == i)
		{
			cards2.erase(cards2.begin());
			continue;
		}
		return "No";
	}
	return "Yes";
}
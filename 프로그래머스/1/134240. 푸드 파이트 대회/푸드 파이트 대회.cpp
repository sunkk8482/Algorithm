#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
	for (int i = 0; i < food.size(); i++)
		food[i] /= 2;

	string r = "";
	for (int i = 1; i < food.size(); i++)
	{
		for (int j = 0; j < food[i]; j++)
		{
			r.push_back('0' + i);
		}
	}
	r.push_back('0');
	for (int i = food.size()-1; i >=1; i--)
	{
		for (int j = 0; j < food[i]; j++)
		{
			r.push_back('0' + i);
		}
	}
	return r;
}
int main()
{
	solution({ 1,7,1,2 });
}
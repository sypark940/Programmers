#include <string>
#include <vector>

using namespace std;

// min 과 max 의 최대공약수를 구하는 함수 (min < max)
int GetGreatestCommandFactor(int min, int max)
{
	if (min == max)
		return 1;

	if (max % min == 0)
		return min;

	for (int ii = min - 1; ii >= 1; ii--)
	{
		if (min % ii == 0 && max % ii == 0)
			return ii;
	}

	return 0;
}

// min 과 max 의 최소공배수 구하는 함수 (gcf : min 과 max 의 최대공약수)
int GetLeastCommomMultiple(int min, int max, int gcf)
{
	return min * max / gcf;
}

vector<int> solution(int n, int m) {
	vector<int> answer;

	int min = (n < m) ? n : m;
	int max = (n < m) ? m : n;

	int gcf = GetGreatestCommandFactor(min, max);
	int lcm = GetLeastCommomMultiple(min, max, gcf);

	answer.push_back(gcf);
	answer.push_back(lcm);
	return answer;
}
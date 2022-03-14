#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	// s 의 모든 숫자 집합을 vecNums 에 저장
	// s = {{3},{3,1},{3,1,4}} -> "3" / "3,1" / "3,1,4"
	string nums;
	vector<string> vecNums;
	for (size_t ii = 1; ii < s.length() - 1; ii++)
	{
		if (s[ii] == '{')
			continue;

		if (s[ii] == '}')
		{
			vecNums.push_back(nums);
			nums = "";
			ii++;
		}
		else
		{
			nums.push_back(s[ii]);
		}
	}

	// vecNums 의 원소를 오름차순 정렬
	sort(vecNums.begin(), vecNums.end(),
		[](string s1, string s2) -> bool {return s1.length() < s2.length(); });

	// 튜플 생성
	answer.push_back(stoi(vecNums.front()));
	for (size_t ii = 1; ii < vecNums.size(); ii++)
	{
		int start_pos = 0;
		int target_pos = vecNums[ii].find(",", start_pos);
		while (target_pos > 0)
		{
			int num = stoi(vecNums[ii].substr(start_pos, target_pos));
			if (find(answer.begin(), answer.end(), num) == answer.end())
				answer.push_back(num);

			start_pos = target_pos + 1;
			target_pos = vecNums[ii].find(",", start_pos);
		}

		int num = stoi(vecNums[ii].substr(start_pos, vecNums[ii].length()));
		if (find(answer.begin(), answer.end(), num) == answer.end())
			answer.push_back(num);
	}

	return answer;
}
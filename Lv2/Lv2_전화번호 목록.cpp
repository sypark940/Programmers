#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	// 모든 전화번호를 key 값으로 가지는 map 생성
	map<string, int> map_phone;
	for (string s : phone_book)
		map_phone[s] = 1;

	// 전화번호부의 각 전화번호에 대해 취할 수 있는 접두어를 가지고
	// 해당 접두어가 map 에 존재하는지 확인
	for (string s : phone_book)
	{
		for (size_t ii = 1; ii < s.length(); ii++)
		{
			string sub_s = s.substr(0, ii);
			if (map_phone[sub_s])
				return false;
		}
	}
	return answer;
}
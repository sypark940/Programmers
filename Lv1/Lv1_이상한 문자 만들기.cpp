#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	// s 에 있는 단어 및 공백문자열을 subString 에저장
	vector<string> subString;
	subString.push_back("");
	for (size_t ii = 0; ii < s.length(); ii++)
	{
		// 아래와 같은 상황일 경우, subString 에 빈 문자열을 새로 추가한다.
		// 1) subString 의 마지막 문자열이 공백인데 현재 문자는 공백문자가 아닌 경우
		// 2) subString 의 마지막 문자열이 단어인데 현재 문자는 공백문자인 경우
		if (!subString.back().empty() &&
			((subString.back().back() == ' ' && s[ii] != ' ')
				|| (subString.back().back() != ' ' && s[ii] == ' ')))
		{
			subString.push_back("");
		}

		subString.back() += s[ii];
	}

	// subString 에 저장된 공백문자열은 그대로 answer 에 추가
	// subString 에저장된 문자는 짝/홀수 인덱스에 따라 대/소문자 전환
	for (string& sub_s : subString)
	{
		for (size_t ii = 0; ii < sub_s.length(); ii++)
		{
			if (sub_s[ii] == ' ')
				answer += sub_s[ii];
			else
				answer += ((ii) % 2 == 0) ? toupper(sub_s[ii]) : tolower(sub_s[ii]);
		}
	}

	return answer;
}
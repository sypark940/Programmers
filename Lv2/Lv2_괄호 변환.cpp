#include <string>
#include <vector>

using namespace std;

bool IsCorrectString(string s)
{
	// 문자열 s에서 () 를 찾으면, ()를 제거 -> 반복
	int pos = s.find("()");
	while (pos >= 0)
	{
		s.erase(s.begin() + pos);
		s.erase(s.begin() + pos);
		pos = s.find("()");
	};

	// 문자열 s에서 () 를 더이상 찾을 수 없는데 s에 원소가 남아있다면,
	// s는 "올바른 괄호 문자열"이 아니다.
	if (!s.empty())
		return false;

	return true;
}

string Execute(string w)
{
	string u = "";
	string v = "";
	string result = "";

	// 1. 입력이 빈 문자열인 경우, 빈 문자열 반환
	if (w.empty())
		return result;

	// 2. 문자열 w 를 두 "균형잡힌 문자열" u, v로 분리 
	int cntRight = 0;
	int cntLeft = 0;
	for (size_t ii = 0; ii < w.length(); ii++)
	{
		if (w[ii] == '(') cntLeft++;
		else if (w[ii] == ')') cntRight++;

		u.push_back(w[ii]);
		if (cntLeft == cntRight)
		{
			v.assign(w.begin() + ii + 1, w.end());
			break;
		}
	}

	// 3. u가 "올바른 괄호 문자열" 인 경우
	if (IsCorrectString(u))
	{
		result = u + Execute(v);
	}
	// 4. u가 "올바른 괄호 문자열" 이 아닌 경우
	else
	{
		result = "(" + Execute(v) + ")";
		for (size_t ii = 1; ii < u.length() - 1; ii++)
		{
			if (u[ii] == '(')
				result.push_back(')');
			else
				result.push_back('(');
		}
	}

	return result;
}

string solution(string p) {
	string answer = Execute(p);
	return answer;
}
#include <string>
#include <vector>

using namespace std;

// 문자 c를 n만큼 민 새로운 문자를 반환하는 함수
char GetNewChar(char c, int n)
{
	char new_c = c;
	for (int ii = 0; ii < n; ii++)
	{
		// a ~ y, A ~ Y 일 경우 1씩 증가
		if ((new_c >= 'a' && new_c < 'z') || (new_c >= 'A' && new_c < 'Z'))
			new_c++;
		// z -> a
		else if (new_c == 'z')
			new_c = 'a';
		// Z -> A
		else if (new_c == 'Z')
			new_c = 'A';
	}

	return new_c;
}

string solution(string s, int n) {
	string answer = "";

	// s 의 원소가 공백이면 answer 에 공백 추가
	// s 의 원소가 알파벳이면 해당 원소를 n 만큼 민 알파벳 추가
	for (auto c : s)
		answer.push_back((c == ' ') ? c : GetNewChar(c, n));

	return answer;
}
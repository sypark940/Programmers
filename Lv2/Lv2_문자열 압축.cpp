#include <string>
#include <vector>

using namespace std;

// num 의 자릿수를 반환해주는 함수
int GetNumSize(int num)
{
	if (num < 10) return 1;

	int den = 10;
	int result = 2;
	while (1)
	{
		if (num % den < 10)
			return result;

		den *= 10;
		result++;
	}
}

int solution(string s) {
	int answer = 0;

	// 최소 1개 단위부터 (s.length()/2) 단위로 자를 수 있다.
	int max_unit = (int)s.length() / 2;

	// 문자열을 자를 수 있는 모든 단위에 대해 압축 문자열의 크기를 구하고,
	// 그 최소값을 min_length 에 저장한다.
	int min_length = s.length();
	for (int unit = 1; unit <= max_unit; unit++)
	{
		// unit 에 따라 문자열을 쪼개서 splitedString 에 저장
		int startPos = 0;
		vector<string> splitedString;
		while (startPos < s.length())
		{
			splitedString.push_back(s.substr(startPos, unit));
			startPos += unit;
		}

		// 압축 문자열의 길이 계산
		int sameCnt = 0;	// 연속된 같은 문자열의 개수
		int length = 0;		// 압축 문자열의 길이

		string prevString = splitedString.front();
		length = (int)prevString.length();
		for (size_t ii = 1; ii < splitedString.size(); ii++)
		{
			// 이전 문자열과 현재 문자열이 같은 경우 -> sameCnt 갱신
			if (prevString == splitedString[ii])
			{
				if (sameCnt == 0)
					sameCnt = 2;
				else
					sameCnt++;

				// 현재 문자열이 splitedString 의 마지막 문자열인 경우
				// -> sameCnt 의 길이 추가
				if (ii == splitedString.size() - 1)
					length += GetNumSize(sameCnt);
			}
			// 이전 문자열과 현재 문자열이 다른 경우
			else
			{
				// length 에 sameCnt 의 길이 추가 및 sameCnt 초기화
				if (sameCnt > 0)
				{
					length += GetNumSize(sameCnt);
					sameCnt = 0;
				}

				// length 에 현재 문자열 길이 추가 (새 문자열)
				length += (int)splitedString[ii].length();
			}

			prevString = splitedString[ii];
		}

		// 압축 문자열의 최소 크기 결정
		if (min_length > length)
			min_length = length;
	}

	answer = min_length;
	return answer;
}
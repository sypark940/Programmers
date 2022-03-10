#include <string>
#include <vector>

using namespace std;

// 2016/1/1 ~ 임의의 날짜까지 경과한 일 수를 입력하면,
// 임의의 날짜에 대한 요일을 반환하는 함수
string GetDay(int days)
{
	switch (days % 7)
	{
	case 0: return "FRI";
	case 1:	return "SAT";
	case 2: return "SUN";
	case 3: return "MON";
	case 4: return "TUE";
	case 5: return "WED";
	case 6: return "THU";
	}

	return "";
};

string solution(int a, int b) {
	string answer = "";

	// 2016/1/1 ~ 2016/a/b 까지 경과한 일 수
	int days = 0;

	// a, b 의 값에 따라 days 결정
	for (int month = 1; month < a; month++)
	{
		switch (month)
		{
		case 2:
			days += 29;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			days += 31;
			break;
		default:
			days += 30;
			break;
		}
	}
	days += (b - 1);

	answer = GetDay(days);
	return answer;
}
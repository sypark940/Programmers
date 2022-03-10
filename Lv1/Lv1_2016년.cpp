#include <string>
#include <vector>

using namespace std;

// 2016/1/1 ~ ������ ��¥���� ����� �� ���� �Է��ϸ�,
// ������ ��¥�� ���� ������ ��ȯ�ϴ� �Լ�
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

	// 2016/1/1 ~ 2016/a/b ���� ����� �� ��
	int days = 0;

	// a, b �� ���� ���� days ����
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
#include <string>
#include <vector>

using namespace std;

// num �� �ڸ����� ��ȯ���ִ� �Լ�
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

	// �ּ� 1�� �������� (s.length()/2) ������ �ڸ� �� �ִ�.
	int max_unit = (int)s.length() / 2;

	// ���ڿ��� �ڸ� �� �ִ� ��� ������ ���� ���� ���ڿ��� ũ�⸦ ���ϰ�,
	// �� �ּҰ��� min_length �� �����Ѵ�.
	int min_length = s.length();
	for (int unit = 1; unit <= max_unit; unit++)
	{
		// unit �� ���� ���ڿ��� �ɰ��� splitedString �� ����
		int startPos = 0;
		vector<string> splitedString;
		while (startPos < s.length())
		{
			splitedString.push_back(s.substr(startPos, unit));
			startPos += unit;
		}

		// ���� ���ڿ��� ���� ���
		int sameCnt = 0;	// ���ӵ� ���� ���ڿ��� ����
		int length = 0;		// ���� ���ڿ��� ����

		string prevString = splitedString.front();
		length = (int)prevString.length();
		for (size_t ii = 1; ii < splitedString.size(); ii++)
		{
			// ���� ���ڿ��� ���� ���ڿ��� ���� ��� -> sameCnt ����
			if (prevString == splitedString[ii])
			{
				if (sameCnt == 0)
					sameCnt = 2;
				else
					sameCnt++;

				// ���� ���ڿ��� splitedString �� ������ ���ڿ��� ���
				// -> sameCnt �� ���� �߰�
				if (ii == splitedString.size() - 1)
					length += GetNumSize(sameCnt);
			}
			// ���� ���ڿ��� ���� ���ڿ��� �ٸ� ���
			else
			{
				// length �� sameCnt �� ���� �߰� �� sameCnt �ʱ�ȭ
				if (sameCnt > 0)
				{
					length += GetNumSize(sameCnt);
					sameCnt = 0;
				}

				// length �� ���� ���ڿ� ���� �߰� (�� ���ڿ�)
				length += (int)splitedString[ii].length();
			}

			prevString = splitedString[ii];
		}

		// ���� ���ڿ��� �ּ� ũ�� ����
		if (min_length > length)
			min_length = length;
	}

	answer = min_length;
	return answer;
}
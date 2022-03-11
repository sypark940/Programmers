#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	// s �� �ִ� �ܾ� �� ���鹮�ڿ��� subString ������
	vector<string> subString;
	subString.push_back("");
	for (size_t ii = 0; ii < s.length(); ii++)
	{
		// �Ʒ��� ���� ��Ȳ�� ���, subString �� �� ���ڿ��� ���� �߰��Ѵ�.
		// 1) subString �� ������ ���ڿ��� �����ε� ���� ���ڴ� ���鹮�ڰ� �ƴ� ���
		// 2) subString �� ������ ���ڿ��� �ܾ��ε� ���� ���ڴ� ���鹮���� ���
		if (!subString.back().empty() &&
			((subString.back().back() == ' ' && s[ii] != ' ')
				|| (subString.back().back() != ' ' && s[ii] == ' ')))
		{
			subString.push_back("");
		}

		subString.back() += s[ii];
	}

	// subString �� ����� ���鹮�ڿ��� �״�� answer �� �߰�
	// subString ������� ���ڴ� ¦/Ȧ�� �ε����� ���� ��/�ҹ��� ��ȯ
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
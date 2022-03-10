#include <string>
#include <vector>

using namespace std;

// ���� c�� n��ŭ �� ���ο� ���ڸ� ��ȯ�ϴ� �Լ�
char GetNewChar(char c, int n)
{
	char new_c = c;
	for (int ii = 0; ii < n; ii++)
	{
		// a ~ y, A ~ Y �� ��� 1�� ����
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

	// s �� ���Ұ� �����̸� answer �� ���� �߰�
	// s �� ���Ұ� ���ĺ��̸� �ش� ���Ҹ� n ��ŭ �� ���ĺ� �߰�
	for (auto c : s)
		answer.push_back((c == ' ') ? c : GetNewChar(c, n));

	return answer;
}
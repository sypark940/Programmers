#include <string>
#include <vector>

using namespace std;

bool IsCorrectString(string s)
{
	// ���ڿ� s���� () �� ã����, ()�� ���� -> �ݺ�
	int pos = s.find("()");
	while (pos >= 0)
	{
		s.erase(s.begin() + pos);
		s.erase(s.begin() + pos);
		pos = s.find("()");
	};

	// ���ڿ� s���� () �� ���̻� ã�� �� ���µ� s�� ���Ұ� �����ִٸ�,
	// s�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴϴ�.
	if (!s.empty())
		return false;

	return true;
}

string Execute(string w)
{
	string u = "";
	string v = "";
	string result = "";

	// 1. �Է��� �� ���ڿ��� ���, �� ���ڿ� ��ȯ
	if (w.empty())
		return result;

	// 2. ���ڿ� w �� �� "�������� ���ڿ�" u, v�� �и� 
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

	// 3. u�� "�ùٸ� ��ȣ ���ڿ�" �� ���
	if (IsCorrectString(u))
	{
		result = u + Execute(v);
	}
	// 4. u�� "�ùٸ� ��ȣ ���ڿ�" �� �ƴ� ���
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
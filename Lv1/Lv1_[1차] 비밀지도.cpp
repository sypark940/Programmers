#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	// arr1 -> table1
	vector<vector<int>> table1;
	for (int num : arr1)
	{
		// table1 �� �� ���͸� �߰��Ͽ� num �� ������ ���� ����
		table1.push_back(vector<int>());
		while (num > 0)
		{
			table1.back().push_back(num % 2);
			num /= 2;
		};

		// num �� �������� �ڸ����� n ���� ������, �� ���̸�ŭ 0 �� �߰�
		size_t cnt = table1.back().size();
		for (size_t ii = 0; ii < n - cnt; ii++)
			table1.back().push_back(0);

		// num �� ������ ������ �������� ����
		reverse(table1.back().begin(), table1.back().end());
	}

	// arr2 -> table2
	vector<vector<int>> table2;
	for (int num : arr2)
	{
		// table2 �� �� ���͸� �߰��Ͽ� num �� ������ ���� ����
		table2.push_back(vector<int>());
		while (num > 0)
		{
			table2.back().push_back(num % 2);
			num /= 2;
		};

		// num �� �������� �ڸ����� n ���� ������, �� ���̸�ŭ 0 �� �߰�
		size_t cnt = table2.back().size();
		for (size_t ii = 0; ii < n - cnt; ii++)
			table2.back().push_back(0);

		// num �� ������ ������ �������� ����
		reverse(table2.back().begin(), table2.back().end());
	}

	// table1 �� table2 �� ��ģ ����� answer �� ����
	for (size_t ii = 0; ii < table1.size() && ii < table2.size(); ii++)
	{
		string sub_s;
		for (size_t jj = 0; jj < table1[ii].size() && jj < table2[ii].size(); jj++)
		{
			sub_s.push_back(table1[ii][jj] || table2[ii][jj] ? '#' : ' ');
		}
		answer.push_back(sub_s);
	}

	return answer;
	return answer;
}
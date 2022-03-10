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
		// table1 에 빈 벡터를 추가하여 num 의 이진수 정보 저장
		table1.push_back(vector<int>());
		while (num > 0)
		{
			table1.back().push_back(num % 2);
			num /= 2;
		};

		// num 의 이진수의 자리수가 n 보다 작으면, 그 차이만큼 0 을 추가
		size_t cnt = table1.back().size();
		for (size_t ii = 0; ii < n - cnt; ii++)
			table1.back().push_back(0);

		// num 의 이진수 정보를 역순으로 변경
		reverse(table1.back().begin(), table1.back().end());
	}

	// arr2 -> table2
	vector<vector<int>> table2;
	for (int num : arr2)
	{
		// table2 에 빈 벡터를 추가하여 num 의 이진수 정보 저장
		table2.push_back(vector<int>());
		while (num > 0)
		{
			table2.back().push_back(num % 2);
			num /= 2;
		};

		// num 의 이진수의 자리수가 n 보다 작으면, 그 차이만큼 0 을 추가
		size_t cnt = table2.back().size();
		for (size_t ii = 0; ii < n - cnt; ii++)
			table2.back().push_back(0);

		// num 의 이진수 정보를 역순으로 변경
		reverse(table2.back().begin(), table2.back().end());
	}

	// table1 과 table2 를 합친 결과를 answer 에 저장
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
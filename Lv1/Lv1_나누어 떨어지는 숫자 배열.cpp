#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	// arr ���� divisor �� ������ �������� ���Ҹ� answer �� ����
	for (int num : arr)
	{
		if (num % divisor == 0)
			answer.push_back(num);
	}

	// answer �������� ����
	sort(answer.begin(), answer.end(), [](int a, int b)->bool {return a < b; });

	// answer �� ����ִ� ���, -1 �߰�
	if (answer.empty())
		answer.push_back(-1);

	return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	// 0 ~ n ������ ������ ����� numbers ���� ����
	vector<int> numbers;
	numbers.resize(n + 1, 0);
	for (int ii = 0; ii <= n; ii++)
		numbers[ii] = ii;

	// �����佺�׳׽��� ü ���
	// numbers ���� ii ���� ū ii �� ����� 0 ���� ġȯ
	for (int ii = 2; ii < n; ii++)
	{
		int num = ii;
		while (num <= n - ii)
		{
			num += ii;
			numbers[num] = 0;
		};
	}

	// �ɷ��� �Ҽ��� ���� ī����
	for (int ii = 0; ii < numbers.size(); ii++)
	{
		if (numbers[ii] != 0)
			answer++;
	}

	// 1�� �Ҽ��� �ƴϹǷ�, 1 ����
	answer--;

	return answer;
}
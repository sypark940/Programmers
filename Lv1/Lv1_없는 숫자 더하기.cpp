#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;

	// 0~9 ������ ������ �Է��� �迭
	vector<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// data �� �� ���Ұ� numbers�� �����ϴ��� Ȯ���ϰ�
	// �������� �ʴ� ���Ҹ� answer �� ����
	for (int d : data)
	{
		if (find(numbers.begin(), numbers.end(), d) == numbers.end())
			answer += d;
	}

	return answer;
}
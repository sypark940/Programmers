#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	// 0 ~ n 까지의 정수가 저장된 numbers 벡터 생성
	vector<int> numbers;
	numbers.resize(n + 1, 0);
	for (int ii = 0; ii <= n; ii++)
		numbers[ii] = ii;

	// 에라토스테네스의 체 사용
	// numbers 에서 ii 보다 큰 ii 의 배수를 0 으로 치환
	for (int ii = 2; ii < n; ii++)
	{
		int num = ii;
		while (num <= n - ii)
		{
			num += ii;
			numbers[num] = 0;
		};
	}

	// 걸러진 소수의 개수 카운팅
	for (int ii = 0; ii < numbers.size(); ii++)
	{
		if (numbers[ii] != 0)
			answer++;
	}

	// 1은 소수가 아니므로, 1 제거
	answer--;

	return answer;
}
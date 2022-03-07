#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;

	// 0~9 까지의 정수를 입력한 배열
	vector<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// data 의 각 원소가 numbers에 존재하는지 확인하고
	// 존재하지 않는 원소를 answer 에 더함
	for (int d : data)
	{
		if (find(numbers.begin(), numbers.end(), d) == numbers.end())
			answer += d;
	}

	return answer;
}
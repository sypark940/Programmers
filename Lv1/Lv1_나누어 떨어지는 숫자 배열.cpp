#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	// arr 에서 divisor 로 나누어 떨어지는 원소를 answer 에 저장
	for (int num : arr)
	{
		if (num % divisor == 0)
			answer.push_back(num);
	}

	// answer 오름차순 정렬
	sort(answer.begin(), answer.end(), [](int a, int b)->bool {return a < b; });

	// answer 이 비어있는 경우, -1 추가
	if (answer.empty())
		answer.push_back(-1);

	return answer;
}
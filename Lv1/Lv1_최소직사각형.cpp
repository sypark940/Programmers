#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	// 명함의 w, h 중 작은 값이 첫 번째, 큰 값이 두 번째에 오도록 정렬
	for (auto& vec : sizes)
		sort(vec.begin(), vec.end());

	// 정렬 후 w, h 의 최대값을 구하여 명합지갑의 크기 계산
	int w_max = 0;
	int h_max = 0;
	for (auto vec : sizes)
	{
		if (w_max < vec[0])	w_max = vec[0];
		if (h_max < vec[1])	h_max = vec[1];
	}

	answer = w_max * h_max;
	return answer;
}
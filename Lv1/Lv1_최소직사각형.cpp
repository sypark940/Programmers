#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;

	// ������ w, h �� ���� ���� ù ��°, ū ���� �� ��°�� ������ ����
	for (auto& vec : sizes)
		sort(vec.begin(), vec.end());

	// ���� �� w, h �� �ִ밪�� ���Ͽ� ���������� ũ�� ���
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
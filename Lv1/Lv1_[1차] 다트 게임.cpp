#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	// dartResult �� �ǹ��ִ� ������ ��� vecResult �� ���� (����, S, D, T, *, #)
	vector<int> vecResult;
	while (!dartResult.empty())
	{
		if (dartResult.find("10") == 0) { vecResult.push_back(10); dartResult.erase(0, 2); }
		else if (dartResult.find("0") == 0) { vecResult.push_back(0); dartResult.erase(0, 1); }
		else if (dartResult.find("1") == 0) { vecResult.push_back(1); dartResult.erase(0, 1); }
		else if (dartResult.find("2") == 0) { vecResult.push_back(2); dartResult.erase(0, 1); }
		else if (dartResult.find("3") == 0) { vecResult.push_back(3); dartResult.erase(0, 1); }
		else if (dartResult.find("4") == 0) { vecResult.push_back(4); dartResult.erase(0, 1); }
		else if (dartResult.find("5") == 0) { vecResult.push_back(5); dartResult.erase(0, 1); }
		else if (dartResult.find("6") == 0) { vecResult.push_back(6); dartResult.erase(0, 1); }
		else if (dartResult.find("7") == 0) { vecResult.push_back(7); dartResult.erase(0, 1); }
		else if (dartResult.find("8") == 0) { vecResult.push_back(8); dartResult.erase(0, 1); }
		else if (dartResult.find("9") == 0) { vecResult.push_back(9); dartResult.erase(0, 1); }
		else if (dartResult.find("S") == 0) { vecResult.push_back(11); dartResult.erase(0, 1); }
		else if (dartResult.find("D") == 0) { vecResult.push_back(12); dartResult.erase(0, 1); }
		else if (dartResult.find("T") == 0) { vecResult.push_back(13); dartResult.erase(0, 1); }
		else if (dartResult.find("*") == 0) { vecResult.push_back(22); dartResult.erase(0, 1); }
		else if (dartResult.find("#") == 0) { vecResult.push_back(-1); dartResult.erase(0, 1); }
	};

	int prevScore = 0;	// �ٷ� ���� ���� ����
	int currScore = 0;	// ���� ����
	for (size_t ii = 0; ii < vecResult.size(); ii++)
	{
		if (vecResult[ii] >= 0 && vecResult[ii] <= 10)
			continue;

		if (ii > 0)
		{
			if (vecResult[ii] == 11)	// S
			{
				prevScore = currScore;
				currScore = pow(vecResult[ii - 1], 1);
				answer += currScore;
			}
			else if (vecResult[ii] == 12)	// D
			{
				prevScore = currScore;
				currScore = pow(vecResult[ii - 1], 2);
				answer += currScore;
			}
			else if (vecResult[ii] == 13)	// T
			{
				prevScore = currScore;
				currScore = pow(vecResult[ii - 1], 3);
				answer += currScore;
			}
			else if (vecResult[ii] == 22)	// *
			{
				// ��Ÿ�� : prevScore �� currScore 2��
				// -> �� ������ prevScore �� currScore �� �� ���� �����ش�. (�̹� �� ���� ���������Ƿ�)
				// -> currScore �� 2��� ����
				answer += (prevScore + currScore);
				currScore *= 2;
			}
			else if (vecResult[ii] == -1)	// #
			{
				// ������ : currScore �� -1�� 
				// -> �� �������� currScore �� �� �� ���ش�. (�̹� �� �� ���� ���� ����� �ϹǷ�)
				// -> currScore �� -1��� ����
				answer -= 2 * currScore;
				currScore *= -1;
			}
		}
	}

	return answer;
}
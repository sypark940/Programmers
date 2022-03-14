#include <string>
#include <vector>

using namespace std;

vector<int> g_numbers;
int g_target = 0;
int g_cnt = 0;

void Add(int currVal, int idx);
void Sub(int currVal, int idx);

void Add(int currVal, int idx)
{
	// 오류
	if (idx >= g_numbers.size())
		return;

	int newVal = currVal + g_numbers[idx];
	if (idx == g_numbers.size() - 1)
	{
		if (newVal == g_target) g_cnt++;
		return;
	}

	Add(newVal, idx + 1);
	Sub(newVal, idx + 1);
}

void Sub(int currVal, int idx)
{
	// 오류
	if (idx >= g_numbers.size())
		return;

	int newVal = currVal - g_numbers[idx];
	if (idx == g_numbers.size() - 1)
	{
		if (newVal == g_target) g_cnt++;
		return;
	}

	Add(newVal, idx + 1);
	Sub(newVal, idx + 1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;

	// 전역변수 초기화
	g_numbers = numbers;
	g_target = target;
	g_cnt = 0;

	// 
	Add(g_numbers[0], 1);
	Sub(g_numbers[0], 1);
	Add(-g_numbers[0], 1);
	Sub(-g_numbers[0], 1);

	answer = g_cnt;
	return answer;
}
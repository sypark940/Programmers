#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	// ��� ��� ���� ������ �Ʒ� ������ �ݺ��Ѵ�.
	int speedIdx_offset = 0;
	while (!progresses.empty())
	{
		// ������ �Ϸ���� ���� ����� �־��� �ӵ��� �����Ѵ�.
		for (size_t ii = 0; ii < progresses.size() && ii < speeds.size(); ii++)
			progresses[ii] += speeds[ii + speedIdx_offset];

		// ���� �ռ� ������ ��� ������ �Ϸ�Ǿ� ������ ������ ���
		if (progresses.front() >= 100)
		{
			// �� ���� ���� ������ �ٸ� ����� �ִ��� Ȯ���ϰ�
			// ���� ������ ��ɵ��� progresses ���� ����
			int completeCnt = 0;
			reverse(progresses.begin(), progresses.end());
			while (!progresses.empty() && progresses.back() >= 100)
			{
				progresses.pop_back();
				completeCnt++;
			};
			speedIdx_offset += completeCnt;
			reverse(progresses.begin(), progresses.end());
			answer.push_back(completeCnt);

		}
	}

	return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	// 모든 기능 배포 전까지 아래 과정을 반복한다.
	int speedIdx_offset = 0;
	while (!progresses.empty())
	{
		// 개발이 완료되지 않은 기능을 주어진 속도로 개발한다.
		for (size_t ii = 0; ii < progresses.size() && ii < speeds.size(); ii++)
			progresses[ii] += speeds[ii + speedIdx_offset];

		// 가장 앞선 순서의 기능 개발이 완료되어 배포가 가능한 경우
		if (progresses.front() >= 100)
		{
			// 한 번에 배포 가능한 다른 기능이 있는지 확인하고
			// 배포 가능한 기능들을 progresses 에서 제거
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
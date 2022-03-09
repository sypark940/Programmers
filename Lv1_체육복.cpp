#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 각 학생이 소유한 체육복의개수를 벡터로 나타낸다.
    vector<int> clothes;
    clothes.resize(n, 1);

    // clothes 에 도난 상태 업데이트
    for (int lost_num : lost)
        clothes[lost_num - 1]--;

    // clotehs 에 여벌 상태 업데이트
    for (int reserve_num : reserve)
        clothes[reserve_num - 1]++;

    // 수업에 참여 가능한 학생의 수
    int studentCnt = 0;

    //
    for (size_t ii = 0; ii < clothes.size(); ii++)
    {
        if (clothes[ii] == 0)
        {
            // 앞에 있는 학생이 여벌의 체육복을 가지고 있는지 확인하고 빌린다.
            if (ii > 0 && clothes[ii - 1] == 2)
            {
                clothes[ii - 1]--;
                clothes[ii]++;
                studentCnt++;
            }
            // 뒤에 있는 학생의 여벌의 체육복을 가지고 있는지 확인하고 빌린다.
            else if (ii < clothes.size() - 1 && clothes[ii + 1] == 2)
            {
                clothes[ii + 1]--;
                clothes[ii]++;
                studentCnt++;
            }
        }
        else
        {
            studentCnt++;
        }
    }

    answer = studentCnt;
    return answer;
}
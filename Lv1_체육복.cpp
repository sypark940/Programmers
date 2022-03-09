#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // �� �л��� ������ ü�����ǰ����� ���ͷ� ��Ÿ����.
    vector<int> clothes;
    clothes.resize(n, 1);

    // clothes �� ���� ���� ������Ʈ
    for (int lost_num : lost)
        clothes[lost_num - 1]--;

    // clotehs �� ���� ���� ������Ʈ
    for (int reserve_num : reserve)
        clothes[reserve_num - 1]++;

    // ������ ���� ������ �л��� ��
    int studentCnt = 0;

    //
    for (size_t ii = 0; ii < clothes.size(); ii++)
    {
        if (clothes[ii] == 0)
        {
            // �տ� �ִ� �л��� ������ ü������ ������ �ִ��� Ȯ���ϰ� ������.
            if (ii > 0 && clothes[ii - 1] == 2)
            {
                clothes[ii - 1]--;
                clothes[ii]++;
                studentCnt++;
            }
            // �ڿ� �ִ� �л��� ������ ü������ ������ �ִ��� Ȯ���ϰ� ������.
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
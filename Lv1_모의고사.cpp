#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // 1, 2, 3 �� �����ڰ� ��� ���
    vector<int> answer1 = { 1,2,3,4,5 };
    vector<int> answer2 = { 2,1,2,3,2,4,2,5 };
    vector<int> answer3 = { 3,3,1,1,2,2,4,4,5,5 };

    // 1, 2, 3 �� �����ڰ� ��� �ݺ��Ǵ� ���� ����
    const size_t cnt1 = answer1.size();
    const size_t cnt2 = answer2.size();
    const size_t cnt3 = answer3.size();

    // 1, 2, 3 �� �������� ����
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;

    // 1, 2, 3 �� �������� �信 �����ϱ� ���� �ε���
    size_t index1 = 0;
    size_t index2 = 0;
    size_t index3 = 0;

    //
    for (size_t ii = 0; ii < answers.size(); ii++)
    {
        // �� �������� ��� ������ ������ ���Ͽ� �������� ������ ����
        if (answer1[index1] == answers[ii]) { score1++; }
        if (answer2[index2] == answers[ii]) { score2++; }
        if (answer3[index3] == answers[ii]) { score3++; }

        // �� �������� �信 �����ϱ� ���� �ε��� ����
        index1++;
        index2++;
        index3++;

        // �� �������� �信 �����ϱ� ���� �ε����� ���� �������� Ŀ���� 0���� �ʱ�ȭ
        if (index1 == cnt1) index1 = 0;
        if (index2 == cnt2) index2 = 0;
        if (index3 == cnt3) index3 = 0;
    }

    // ���� ���� ���� Ȯ��
    int max_score = score1;
    if (max_score < score2) max_score = score2;
    if (max_score < score3) max_score = score3;

    // ���� ���� ������ ���� �����ڸ� answer �� ����
    if (max_score == score1) answer.push_back(1);
    if (max_score == score2) answer.push_back(2);
    if (max_score == score3) answer.push_back(3);

    // asnwer �� �������� ����
    sort(answer.begin(), answer.end(), [](int a, int b)-> bool {return a < b;});

    return answer;
}
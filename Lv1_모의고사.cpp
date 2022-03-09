#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // 1, 2, 3 번 수포자가 찍는 방식
    vector<int> answer1 = { 1,2,3,4,5 };
    vector<int> answer2 = { 2,1,2,3,2,4,2,5 };
    vector<int> answer3 = { 3,3,1,1,2,2,4,4,5,5 };

    // 1, 2, 3 번 수포자가 찍는 반복되는 답의 개수
    const size_t cnt1 = answer1.size();
    const size_t cnt2 = answer2.size();
    const size_t cnt3 = answer3.size();

    // 1, 2, 3 번 수포자의 점수
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;

    // 1, 2, 3 번 수포자의 답에 접근하기 위한 인덱스
    size_t index1 = 0;
    size_t index2 = 0;
    size_t index3 = 0;

    //
    for (size_t ii = 0; ii < answers.size(); ii++)
    {
        // 각 수포자의 답과 문제의 정답을 비교하여 수포자의 점수를 갱신
        if (answer1[index1] == answers[ii]) { score1++; }
        if (answer2[index2] == answers[ii]) { score2++; }
        if (answer3[index3] == answers[ii]) { score3++; }

        // 각 수포자의 답에 접근하기 위한 인덱스 갱신
        index1++;
        index2++;
        index3++;

        // 각 수포자의 답에 접근하기 위한 인덱스가 답의 개수보다 커지면 0으로 초기화
        if (index1 == cnt1) index1 = 0;
        if (index2 == cnt2) index2 = 0;
        if (index3 == cnt3) index3 = 0;
    }

    // 가장 높은 점수 확인
    int max_score = score1;
    if (max_score < score2) max_score = score2;
    if (max_score < score3) max_score = score3;

    // 가장 높은 점수를 받은 수포자를 answer 에 저장
    if (max_score == score1) answer.push_back(1);
    if (max_score == score2) answer.push_back(2);
    if (max_score == score3) answer.push_back(3);

    // asnwer 를 오름차순 정렬
    sort(answer.begin(), answer.end(), [](int a, int b)-> bool {return a < b;});

    return answer;
}
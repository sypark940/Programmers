using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (long long)money;

    // 놀이기구를 count 번 탈 경우의 총 지불 금액을 계산
    long long pay = 0;
    for (int ii = 1; ii <= count; ii++)
    {
        pay += (ii * price);
    }

    // 가지고 있는 금액이 부족하지 않은 경우 -> 0
    // 가지고 있는 금액이 부족한 경우 -> 모자란 금액 리턴
    if (pay < money)
        answer = 0;
    else
        answer = pay - money;

    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;

    if (num == 1)
    {
        answer = 0;
    }
    else
    {
        long number = (long)num;

        // �ݶ��������� 500 �̸����� �ݺ�
        int iterCnt = 0;
        while (iterCnt < 500)
        {
            iterCnt++;
            number = (number % 2 == 0) ? number / 2 : number * 3 + 1;

            // num �� 1�� ������ ����
            if (number == 1)
                break;
        }

        answer = (number == 1) ? iterCnt : -1;
    }

    return answer;
}
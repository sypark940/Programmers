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

        // 콜라츠추측을 500 미만으로 반복
        int iterCnt = 0;
        while (iterCnt < 500)
        {
            iterCnt++;
            number = (number % 2 == 0) ? number / 2 : number * 3 + 1;

            // num 이 1이 됐으면 종료
            if (number == 1)
                break;
        }

        answer = (number == 1) ? iterCnt : -1;
    }

    return answer;
}
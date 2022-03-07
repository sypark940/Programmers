#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int leftPos = 10;   // 왼쪽 손가락 시작 위치 (*)
    int rightPos = 12;  // 오른쪽 손가락 시작 위치 (#)

    // 손가락의 현재 위치와 이전 위치 사이의 관계를 가지고 이동할 거리를 계산하는 함수
    auto CalDist = [](int currentPos, int prevPos) -> int
    {
        int del = abs(currentPos - prevPos);

        if (del == 1 || del == 3)
            return 1;
        else if (del == 2 || del == 4 || del == 6)
            return 2;
        else if (del == 5 || del == 7 || del == 9)
            return 3;
        else if (del == 8 || del == 10)
            return 4;

        return 0;
    };

    for (size_t ii = 0; ii < numbers.size(); ii++)
    {
        int num = numbers[ii];
        bool rightInput = true;

        // 1, 4, 7 -> 왼쪽 손가락으로 입력
        if (num == 1 || num == 4 || num == 7)
        {
            rightInput = false;
        }
        // 3, 6, 9 -> 오른쪽 손가락으로 입력
        if (num == 3 || num == 6 || num == 9)
        {
            rightInput = true;
        }
        // 2, 5, 8, 0 -> 더 가까운 손가락으로 입력
        else if (num == 2 || num == 5 || num == 8 || num == 0)
        {
            // 거리 계산이 쉽도록, 0은 11로 변경 (*는 10, #은 12)
            if (num == 0)
                num = 11;

            // 양쪽 손가락 위치와 num 과의 거리 계산
            int leftDist = CalDist(num, leftPos);
            int rightDist = CalDist(num, rightPos);

            
            // 왼쪽 손가락이 더 먼 경우 -> 오른손 입력
            if (leftDist > rightDist)
            {
                rightInput = true;
            }
            // 오른쪽 손가락이 더 먼 경우 -> 왼손 입력
            else if (leftDist < rightDist)
            {
                rightInput = false;
            }
            // 양쪽 손가락으로부터의 거리가 같은 경우 -> 오른손잡이인지 왼손잡이인지에 따라 결정
            else
            {
                rightInput = (hand == "right") ? true : false;
            }
        }

        if (rightInput)
        {
            answer.push_back('R');
            rightPos = num;
        }
        else
        {
            answer.push_back('L');
            leftPos = num;
        }
    }

    return answer;
}
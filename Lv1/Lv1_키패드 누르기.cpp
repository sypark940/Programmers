#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int leftPos = 10;   // ���� �հ��� ���� ��ġ (*)
    int rightPos = 12;  // ������ �հ��� ���� ��ġ (#)

    // �հ����� ���� ��ġ�� ���� ��ġ ������ ���踦 ������ �̵��� �Ÿ��� ����ϴ� �Լ�
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

        // 1, 4, 7 -> ���� �հ������� �Է�
        if (num == 1 || num == 4 || num == 7)
        {
            rightInput = false;
        }
        // 3, 6, 9 -> ������ �հ������� �Է�
        if (num == 3 || num == 6 || num == 9)
        {
            rightInput = true;
        }
        // 2, 5, 8, 0 -> �� ����� �հ������� �Է�
        else if (num == 2 || num == 5 || num == 8 || num == 0)
        {
            // �Ÿ� ����� ������, 0�� 11�� ���� (*�� 10, #�� 12)
            if (num == 0)
                num = 11;

            // ���� �հ��� ��ġ�� num ���� �Ÿ� ���
            int leftDist = CalDist(num, leftPos);
            int rightDist = CalDist(num, rightPos);

            
            // ���� �հ����� �� �� ��� -> ������ �Է�
            if (leftDist > rightDist)
            {
                rightInput = true;
            }
            // ������ �հ����� �� �� ��� -> �޼� �Է�
            else if (leftDist < rightDist)
            {
                rightInput = false;
            }
            // ���� �հ������κ����� �Ÿ��� ���� ��� -> �������������� �޼����������� ���� ����
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
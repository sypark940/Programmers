#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    // ������ ���� �ٱ���
    stack<int> basket;

    // �ٱ��Ͽ� �������� ���� ���� ������ ���� ����
    int sameCnt = 1;

    // ũ������ �۵� ��ġ�� ����
    for (int move : moves)
    {
        // zero base �� ��ȯ
        move -= 1;

        for (auto& row : board)
        {
            // ũ������ move ��ġ���� ���� �� �ִ� ������ �����ϴ� ���
            if (row[move] > 0)
            {
                // ���� ������ basket �� ���� ���� ���� ������ ���� ������ sameCnt ����, �ٸ� ������ sameKind �ʱ�ȭ
                if (!basket.empty())
                {
                    if (basket.top() != row[move])
                        sameCnt = 1;
                    else
                        sameCnt++;
                }

                // ������ �ٱ��Ͽ� �߰��ϰ�, �ش� ������ �� ���� ó��
                basket.push(row[move]);
                row[move] = 0;

                // basket �� ���� ������ ������ 2�� ���̸� ����
                // ����� ������ ���� �� �ٱ��Ͽ� ���� ���� ������ ������ ���� ����
                if (sameCnt == 2)
                {
                    basket.pop();
                    basket.pop();
                    answer += 2;

                    sameCnt -= 2;
                    if (sameCnt == 0)
                        sameCnt = 1;
                }

                break;
            }
        }
    }

    return answer;
}
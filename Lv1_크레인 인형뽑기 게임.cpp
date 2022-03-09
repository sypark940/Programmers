#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    // 인형을 쌓을 바구니
    stack<int> basket;

    // 바구니에 연속으로 쌓인 같은 종류의 인형 개수
    int sameCnt = 1;

    // 크레인의 작동 위치에 접근
    for (int move : moves)
    {
        // zero base 로 변환
        move -= 1;

        for (auto& row : board)
        {
            // 크레인이 move 위치에서 집을 수 있는 인형이 존재하는 경우
            if (row[move] > 0)
            {
                // 집은 인형이 basket 에 가장 위에 쌓인 인형과 같은 종류면 sameCnt 갱신, 다른 종류면 sameKind 초기화
                if (!basket.empty())
                {
                    if (basket.top() != row[move])
                        sameCnt = 1;
                    else
                        sameCnt++;
                }

                // 인형을 바구니에 추가하고, 해당 공간을 빈 공간 처리
                basket.push(row[move]);
                row[move] = 0;

                // basket 에 같은 종류의 인형이 2개 쌓이면 제거
                // 사라진 인형의 개수 및 바구니에 쌓인 같은 종류의 인형의 개수 갱신
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
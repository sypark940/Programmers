#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int matchingCnt = 0;        // 구매한 로또 번호 중 당첨 번호와 일치하는 번호의 개수
    int zeroCnt = 0;            // 구매한 로또 번호 중 알 수 없는 번호의 개수

    for (int const& num : lottos)
    {
        // num 이 0일 경우 -> zeroCnt 갱신
        if (num == 0)
        {
            zeroCnt++;
        }
        // num 이 0이 아닌 경우
        else
        {
            // num 이 당첨 번호라면, 당첨 번호 목록에서 num 을 제거하고 matchingCnt 를 갱신한다.
            auto iter = find(win_nums.begin(), win_nums.end(), num);
            if (iter != win_nums.end())
            {
                win_nums.erase(iter);
                matchingCnt++;
            }
        }
    }

    int winCnt = (int)win_nums.size();

    // 최저 및 최고 당첨 개수 계산
    // 1) zeroCnt >= winCnt : 최대 winCnt 만큼 더 맞출 수 있음
    // 2) zeroCnt <  winCnt : 최대 zeroCnt 만큼 더 맞출 수 있음
    int minCnt = matchingCnt;
    int maxCnt = (zeroCnt >= winCnt ? matchingCnt + winCnt : matchingCnt + zeroCnt);

    // 당첨 번호의 개수로부터 순위를 반환해주는 함수
    auto GetLank = [](int cnt) -> int {

        switch (cnt)
        {
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3: return 4;
        case 2: return 5;
        }
        return 6;
    };

    answer.push_back(GetLank(maxCnt));
    answer.push_back(GetLank(minCnt));
    return answer;
}
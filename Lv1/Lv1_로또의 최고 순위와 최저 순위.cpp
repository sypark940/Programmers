#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int matchingCnt = 0;        // ������ �ζ� ��ȣ �� ��÷ ��ȣ�� ��ġ�ϴ� ��ȣ�� ����
    int zeroCnt = 0;            // ������ �ζ� ��ȣ �� �� �� ���� ��ȣ�� ����

    for (int const& num : lottos)
    {
        // num �� 0�� ��� -> zeroCnt ����
        if (num == 0)
        {
            zeroCnt++;
        }
        // num �� 0�� �ƴ� ���
        else
        {
            // num �� ��÷ ��ȣ���, ��÷ ��ȣ ��Ͽ��� num �� �����ϰ� matchingCnt �� �����Ѵ�.
            auto iter = find(win_nums.begin(), win_nums.end(), num);
            if (iter != win_nums.end())
            {
                win_nums.erase(iter);
                matchingCnt++;
            }
        }
    }

    int winCnt = (int)win_nums.size();

    // ���� �� �ְ� ��÷ ���� ���
    // 1) zeroCnt >= winCnt : �ִ� winCnt ��ŭ �� ���� �� ����
    // 2) zeroCnt <  winCnt : �ִ� zeroCnt ��ŭ �� ���� �� ����
    int minCnt = matchingCnt;
    int maxCnt = (zeroCnt >= winCnt ? matchingCnt + winCnt : matchingCnt + zeroCnt);

    // ��÷ ��ȣ�� �����κ��� ������ ��ȯ���ִ� �Լ�
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
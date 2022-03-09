#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    // 연구실에 있는 포켓몬의 개수
    int cnt = nums.size();

    // key : 포켓몬의 종류, val : key 에 해당하는 종류의 포켓몬 개수
    map<int, int> mapPoketmons;

    for (int num : nums)
    {
        // num 종류의 포켓몬이 mapPoketmons 에 없다면 추가하고 개수를 1로 초기화
        // num 종류의 포켓몬이 mapPoketmons 에 있다면 개수 증가

        if (mapPoketmons.find(num) == mapPoketmons.end())
            mapPoketmons[num] = 1;
        else
            mapPoketmons[num]++;
    }

    // 가져갈 수 있는 포켓몬의 개수보다 mapPoketmons 에 저장된 종류가 적으면, mapPoketmons 에 저장된 종류만큼 가져간다.
    // 가져갈 수 있는 포켓몬의 개수보다 mapPoketmons 에 저장된 종류가 많거나 같으면, 최대로 가져간다.
    if (mapPoketmons.size() < cnt / 2)
        answer = (int)mapPoketmons.size();
    else
        answer = cnt / 2;

    return answer;
}
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    // �����ǿ� �ִ� ���ϸ��� ����
    int cnt = nums.size();

    // key : ���ϸ��� ����, val : key �� �ش��ϴ� ������ ���ϸ� ����
    map<int, int> mapPoketmons;

    for (int num : nums)
    {
        // num ������ ���ϸ��� mapPoketmons �� ���ٸ� �߰��ϰ� ������ 1�� �ʱ�ȭ
        // num ������ ���ϸ��� mapPoketmons �� �ִٸ� ���� ����

        if (mapPoketmons.find(num) == mapPoketmons.end())
            mapPoketmons[num] = 1;
        else
            mapPoketmons[num]++;
    }

    // ������ �� �ִ� ���ϸ��� �������� mapPoketmons �� ����� ������ ������, mapPoketmons �� ����� ������ŭ ��������.
    // ������ �� �ִ� ���ϸ��� �������� mapPoketmons �� ����� ������ ���ų� ������, �ִ�� ��������.
    if (mapPoketmons.size() < cnt / 2)
        answer = (int)mapPoketmons.size();
    else
        answer = cnt / 2;

    return answer;
}
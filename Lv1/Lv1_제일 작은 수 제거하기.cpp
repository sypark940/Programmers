#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    // arr �� ������ �迭�� ������������ ����
    vector<int> arr_copied = arr;
    sort(arr_copied.begin(), arr_copied.end(), [](int a, int b)->bool {return a > b;});

    // arr_copied �� ���� ������ ���� (���� ���� ����) �� ã�Ƽ� arr ���� ����
    int min = arr_copied.back();
    auto iter = find(arr.begin(), arr.end(), min);
    if (iter != arr.end())
        arr.erase(iter);

    // ���� ���� ���� ���ŵ� arr �� answer �� ����
    // (��, arr �� �� �迭�� ��� answer �� -1 �߰�)
    answer = arr;
    if (answer.empty())
        answer.push_back(-1);

    return answer;
}
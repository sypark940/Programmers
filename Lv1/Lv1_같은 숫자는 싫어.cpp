#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    // arr �� ù ��° ���Ҹ� answer �� ����
    answer.push_back(arr.front());

    //
    for (size_t ii = 1; ii < arr.size(); ii++)
    {
        // ���� ���Ұ� �̹� answer �� �������� ����Ǿ� ������ �Ѿ��.
        if (answer.back() == arr[ii])
            continue;

        answer.push_back(arr[ii]);
    }

    return answer;
}
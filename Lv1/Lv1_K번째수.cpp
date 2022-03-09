#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto command : commands)
    {
        // i��° ~ j���簡�� �ڸ� ������ �迭
        vector<int> sub_array;
        sub_array.assign(array.begin() + command[0] - 1, array.begin() + command[1]);

        // sub_array ����
        sort(sub_array.begin(), sub_array.end(), [](int a, int b)->bool {return a < b;});

        // sub_array �� k��° ���� answer �� ����
        answer.push_back(sub_array[command[2] - 1]);
    }

    return answer;
}
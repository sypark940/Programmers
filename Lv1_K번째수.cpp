#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto command : commands)
    {
        // i번째 ~ j번재가지 자른 숫자의 배열
        vector<int> sub_array;
        sub_array.assign(array.begin() + command[0] - 1, array.begin() + command[1]);

        // sub_array 정렬
        sort(sub_array.begin(), sub_array.end(), [](int a, int b)->bool {return a < b;});

        // sub_array 의 k번째 수를 answer 에 저장
        answer.push_back(sub_array[command[2] - 1]);
    }

    return answer;
}
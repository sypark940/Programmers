#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    // arr 의 첫 번째 원소를 answer 에 저장
    answer.push_back(arr.front());

    //
    for (size_t ii = 1; ii < arr.size(); ii++)
    {
        // 현재 원소가 이미 answer 의 마지막에 저장되어 있으면 넘어간다.
        if (answer.back() == arr[ii])
            continue;

        answer.push_back(arr[ii]);
    }

    return answer;
}
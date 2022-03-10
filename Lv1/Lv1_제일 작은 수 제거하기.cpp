#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    // arr 를 복사한 배열을 내림차순으로 정렬
    vector<int> arr_copied = arr;
    sort(arr_copied.begin(), arr_copied.end(), [](int a, int b)->bool {return a > b;});

    // arr_copied 의 가장 마지막 원소 (가장 작은 원소) 를 찾아서 arr 에서 제거
    int min = arr_copied.back();
    auto iter = find(arr.begin(), arr.end(), min);
    if (iter != arr.end())
        arr.erase(iter);

    // 가장 작은 수가 제거된 arr 를 answer 에 복사
    // (단, arr 가 빈 배열일 경우 answer 에 -1 추가)
    answer = arr;
    if (answer.empty())
        answer.push_back(-1);

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    // numbers 에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 answer 에 추가 (중복 제외)
    for (size_t ii = 0; ii < numbers.size() - 1; ii++)
    {
        for (size_t jj = ii + 1; jj < numbers.size(); jj++)
        {
            int sum = numbers[ii] + numbers[jj];
            if (find(answer.begin(), answer.end(), sum) == answer.end())
                answer.push_back(sum);
        }
    }

    // answer 을 오름차순 정렬
    sort(answer.begin(), answer.end(), [](int a, int b)->bool {return a < b;});

    return answer;
}
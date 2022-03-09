#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    // numbers ���� ���� �ٸ� �ε����� �ִ� �� ���� ���� �̾� ���ؼ� answer �� �߰� (�ߺ� ����)
    for (size_t ii = 0; ii < numbers.size() - 1; ii++)
    {
        for (size_t jj = ii + 1; jj < numbers.size(); jj++)
        {
            int sum = numbers[ii] + numbers[jj];
            if (find(answer.begin(), answer.end(), sum) == answer.end())
                answer.push_back(sum);
        }
    }

    // answer �� �������� ����
    sort(answer.begin(), answer.end(), [](int a, int b)->bool {return a < b;});

    return answer;
}
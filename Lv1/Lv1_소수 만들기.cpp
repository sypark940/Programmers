#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    // num 이 소수인지 판별하는 함수
    auto IsPrimeNum = [](int num) -> bool {

        // 1, 2, 3 은 직접 판별
        if (num == 1) return false;
        if (num == 2) return true;
        if (num == 3) return true;

        // 1과 자기 자신 이외에 다른 수로 나누어 떨어지면 소수 X
        for (int idx = 2; idx < num; idx++)
        {
            if (num % idx == 0)
                return false;
        }

        return true;
    };

    //
    for (size_t ii = 0; ii < nums.size() - 2; ii++)
    {
        for (size_t jj = ii + 1; jj < nums.size() - 1; jj++)
        {
            for (size_t kk = jj + 1; kk < nums.size(); kk++)
            {
                // nums 에서 서로 다른 세 개의 숫자를 골라 더하고, 소수인지 판별
                int sum = nums[ii] + nums[jj] + nums[kk];
                if (IsPrimeNum(sum))
                    answer++;
            }
        }
    }
    return answer;
}
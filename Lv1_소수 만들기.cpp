#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    // num �� �Ҽ����� �Ǻ��ϴ� �Լ�
    auto IsPrimeNum = [](int num) -> bool {

        // 1, 2, 3 �� ���� �Ǻ�
        if (num == 1) return false;
        if (num == 2) return true;
        if (num == 3) return true;

        // 1�� �ڱ� �ڽ� �̿ܿ� �ٸ� ���� ������ �������� �Ҽ� X
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
                // nums ���� ���� �ٸ� �� ���� ���ڸ� ��� ���ϰ�, �Ҽ����� �Ǻ�
                int sum = nums[ii] + nums[jj] + nums[kk];
                if (IsPrimeNum(sum))
                    answer++;
            }
        }
    }
    return answer;
}
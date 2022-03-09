#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    // 부서별 신청 금액을 오름차순 정렬
    sort(d.begin(), d.end(), [](int a, int b) -> bool {return a < b;});

    // 신청 금액이 작은 부서부터 물품 구매 지원
    for (int const& dd : d)
    {
        // 신청 금액보다 예산이 적으면 지원 종료
        if (budget < dd)
            break;

        // 예산에서 신청 금액 제외 및 신청 부서의 개수 업데이트
        budget -= dd;
        answer++;
    }

    return answer;
}
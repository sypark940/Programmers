#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    // �μ��� ��û �ݾ��� �������� ����
    sort(d.begin(), d.end(), [](int a, int b) -> bool {return a < b;});

    // ��û �ݾ��� ���� �μ����� ��ǰ ���� ����
    for (int const& dd : d)
    {
        // ��û �ݾ׺��� ������ ������ ���� ����
        if (budget < dd)
            break;

        // ���꿡�� ��û �ݾ� ���� �� ��û �μ��� ���� ������Ʈ
        budget -= dd;
        answer++;
    }

    return answer;
}
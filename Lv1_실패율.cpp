#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    map<int, int> mapStage;                     // key : �������� ��ȣ, val : ������ �÷��̾� ��
    map<int, int> mapFail;                      // key : �������� ��ȣ, val : Ŭ������ �÷��̾� ��
    vector<pair<int, double>> vecFailRate;     // key : �������� ��ȣ, val : ������

    for (int ii = 1; ii <= N; ii++)
    {
        mapStage[ii] = 0;
        mapFail[ii] = 0;
        vecFailRate.push_back({ ii - 1, 0.0 });
    }

    // �� ���������� ���� �� Ŭ������ �÷��̾��� ���� �ľ�
    for (int stage : stages)
    {
        // �÷��̾ ���� ���������� ���������Ƿ�, ���� ���������� ������ ��� ���������� ���� ó��
        for (int ii = 1; ii <= stage; ii++)
            mapStage[ii]++;

        // �÷��̾ ���� ���������� ���� �����Ƿ�, ���� �������� ���� ó��
        // (��� ���������� Ŭ������ �÷��̾� ����)
        if (stage <= N)
            mapFail[stage]++;
    }

    // �������� ����Ͽ� vecFailRate �� ����
    for (int ii = 0; ii < N; ii++)
    {
        if (mapStage[ii + 1] == 0)
            vecFailRate[ii].second = 0;
        else
            vecFailRate[ii].second = (double)mapFail[ii + 1] / mapStage[ii + 1];
    }

    // vecFailRate ����
    sort(vecFailRate.begin(), vecFailRate.end()
        , [](pair<int, double> a, pair<int, double> b)->bool {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });

    for (int ii = 0; ii < N; ii++)
        answer.push_back(vecFailRate[ii].first + 1);
    return answer;
}
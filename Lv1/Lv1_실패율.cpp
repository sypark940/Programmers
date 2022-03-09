#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    map<int, int> mapStage;                     // key : 스테이지 번호, val : 도달한 플레이어 수
    map<int, int> mapFail;                      // key : 스테이지 번호, val : 클리어한 플레이어 수
    vector<pair<int, double>> vecFailRate;     // key : 스테이지 번호, val : 실패율

    for (int ii = 1; ii <= N; ii++)
    {
        mapStage[ii] = 0;
        mapFail[ii] = 0;
        vecFailRate.push_back({ ii - 1, 0.0 });
    }

    // 각 스테이지에 도달 및 클리어한 플레이어의 수를 파악
    for (int stage : stages)
    {
        // 플레이어가 현재 스테이지에 도달했으므로, 현재 스테이지를 포함한 모든 스테이지에 도달 처리
        for (int ii = 1; ii <= stage; ii++)
            mapStage[ii]++;

        // 플레이어가 현재 스테이지에 멈춰 있으므로, 현재 스테이지 실패 처리
        // (모든 스테이지를 클리어한 플레이어 제외)
        if (stage <= N)
            mapFail[stage]++;
    }

    // 실패율을 계산하여 vecFailRate 에 저장
    for (int ii = 0; ii < N; ii++)
    {
        if (mapStage[ii + 1] == 0)
            vecFailRate[ii].second = 0;
        else
            vecFailRate[ii].second = (double)mapFail[ii + 1] / mapStage[ii + 1];
    }

    // vecFailRate 정렬
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
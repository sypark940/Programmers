#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    // rows x columns ��� ����
    vector<vector<int>> table;
    int num = 1;
    for (size_t ii = 0; ii < rows; ii++)
    {
        table.push_back(vector<int>(columns));
        for (size_t jj = 0; jj < columns; jj++)
        {
            table.back()[jj] = num;
            num++;
        }
    }

    //
    for (auto query : queries)
    {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        // table�� (x1,y1) ~ (x2,y2) ���� �׵θ��� �ִ� ���ڸ� ������� ����
        vector<int> boundaryNums;
        for (int ii = y1; ii <= y2; ii++)       boundaryNums.push_back(table[x1][ii]);
        for (int ii = x1 + 1; ii <= x2; ii++)     boundaryNums.push_back(table[ii][y2]);
        for (int ii = y2 - 1; ii >= y1; ii--)     boundaryNums.push_back(table[x2][ii]);
        for (int ii = x2 - 1; ii >= x1; ii--)      boundaryNums.push_back(table[ii][y1]);

        // �׵θ��� �ִ� ���ڵ��� ȸ�� ����
        boundaryNums.insert(boundaryNums.begin(), boundaryNums.back());
        boundaryNums.pop_back();

        // table�� (x1,y1) ~ (x2,y2) ���� �׵θ��� boundaryNums �� ������� ����
        int idx = 0;
        for (int ii = y1; ii <= y2; ii++)       table[x1][ii] = boundaryNums[idx++];
        for (int ii = x1 + 1; ii <= x2; ii++)     table[ii][y2] = boundaryNums[idx++];
        for (int ii = y2 - 1; ii >= y1; ii--)     table[x2][ii] = boundaryNums[idx++];
        for (int ii = x2 - 1; ii >= x1; ii--)      table[ii][y1] = boundaryNums[idx++];

        // �����ߴ� ���ڵ��� �������� �����ϰ�, �� �� ���� ���� ���ڸ� answer �� �߰�
        sort(boundaryNums.begin(), boundaryNums.end());
        answer.push_back(boundaryNums.front());
    }

    return answer;
}
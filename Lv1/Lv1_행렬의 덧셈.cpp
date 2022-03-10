#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (size_t ii = 0; ii < arr1.size() && ii < arr2.size(); ii++)
    {
        answer.push_back(vector<int>(arr1[ii].size(), 0));

        for (size_t jj = 0; jj < arr1[ii].size() && jj < arr2[ii].size(); jj++)
        {
            answer.back()[jj] = arr1[ii][jj] + arr2[ii][jj];
        }
    }
    return answer;
}
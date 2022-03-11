#include <vector>

using namespace std;

int g_row_max;
int g_col_max;
vector<vector<int>> g_picture;

void visitArea(int area_num, int row, int col, int& area_size)
{
	// 현재 위치가 이미 방문처리 되었거나
	// area_num 번호에 해당하는 영역이 아니면 종료
	if (g_picture[row][col] != area_num)
		return;

	// 현재 위치 방문처리 및 area_num 영역의 사이즈 갱신
	g_picture[row][col] = 0;
	area_size++;

	// 상
	if (row > 0)
		visitArea(area_num, row - 1, col, area_size);

	// 하
	if (row < g_row_max - 1)
		visitArea(area_num, row + 1, col, area_size);

	// 좌
	if (col > 0)
		visitArea(area_num, row, col - 1, area_size);

	// 우
	if (col < g_col_max - 1)
		visitArea(area_num, row, col + 1, area_size);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	// 전역 변수 초기화
	g_row_max = m;
	g_col_max = n;
	g_picture = picture;

	//
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (size_t row = 0; row < m; row++)
	{
		for (size_t col = 0; col < n; col++)
		{
			// 현재 위치가 비어있다면 넘어간다.
			if (g_picture[row][col] == 0)
				continue;

			// 새 영역에 방문한다.
			int number = g_picture[row][col];		// number: 새로 도달한 영역의 번호
			int area_size = 0;					// area_size: number 영역의 크기
			visitArea(number, row, col, area_size);

			// 방문 영역의 크기에 따라 max_size_of_one_area 갱신
			if (max_size_of_one_area < area_size)
				max_size_of_one_area = area_size;

			// 영역의 개수 갱신
			number_of_area++;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
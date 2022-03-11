#include <vector>

using namespace std;

int g_row_max;
int g_col_max;
vector<vector<int>> g_picture;

void visitArea(int area_num, int row, int col, int& area_size)
{
	// ���� ��ġ�� �̹� �湮ó�� �Ǿ��ų�
	// area_num ��ȣ�� �ش��ϴ� ������ �ƴϸ� ����
	if (g_picture[row][col] != area_num)
		return;

	// ���� ��ġ �湮ó�� �� area_num ������ ������ ����
	g_picture[row][col] = 0;
	area_size++;

	// ��
	if (row > 0)
		visitArea(area_num, row - 1, col, area_size);

	// ��
	if (row < g_row_max - 1)
		visitArea(area_num, row + 1, col, area_size);

	// ��
	if (col > 0)
		visitArea(area_num, row, col - 1, area_size);

	// ��
	if (col < g_col_max - 1)
		visitArea(area_num, row, col + 1, area_size);
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	// ���� ���� �ʱ�ȭ
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
			// ���� ��ġ�� ����ִٸ� �Ѿ��.
			if (g_picture[row][col] == 0)
				continue;

			// �� ������ �湮�Ѵ�.
			int number = g_picture[row][col];		// number: ���� ������ ������ ��ȣ
			int area_size = 0;					// area_size: number ������ ũ��
			visitArea(number, row, col, area_size);

			// �湮 ������ ũ�⿡ ���� max_size_of_one_area ����
			if (max_size_of_one_area < area_size)
				max_size_of_one_area = area_size;

			// ������ ���� ����
			number_of_area++;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
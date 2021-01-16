#include <iostream>
#include <cstring>
using namespace std;

int cnt = 0;
int length;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
void explorer(int** map, int row, int col)
{
	if (map[row][col] == 1)
	{
		map[row][col] = cnt;
		if (row > 0 && map[row - 1][col]) explorer(map, row - 1, col);
		if (col < length - 1 && map[row][col + 1]) explorer(map, row, col + 1);
		if (row < length - 1 && map[row + 1][col]) explorer(map, row + 1, col);
		if (col > 0 && map[row][col - 1]) explorer(map, row, col - 1);
	}
}


int main()
{
	int** arr;
	int* danji_name;
	cin >> length;

	// 2차원 배열 동적 할당.
	arr = new int* [length];
	for (int i = 0; i < length; i++)
		arr[i] = new int[length];

	// 2차원 배열 입력
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (arr[i][j] == 1)
			{
				cnt--;
				explorer(arr, i, j);
			}
		}
	}
	
	// 단지 숫자 구하는 배열 선언
	danji_name = new int[cnt * -1];
	memset(danji_name, 0, sizeof(int) * cnt * -1);

	// 각 단지 동수 구하기
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (arr[i][j] != 0)
			{
				arr[i][j] *= -1;
				for (int k = 1; k <= (cnt * -1); k++)
				{
					if (arr[i][j] == k) danji_name[k - 1]++;
				}
			}
		}
	}
	
	cout << cnt * -1 << endl;

	for (int i = 0; i < cnt * -1; i++)
		cout << danji_name[i] << endl;

	for (int i = 0; i < length; i++)
		delete[] arr[i];

	delete[]danji_name;
	return 0;
}
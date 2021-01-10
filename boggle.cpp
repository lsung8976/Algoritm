#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char map1[5][5] = { 'U','R','L','P','M',
					'X','P','R','E','T',
					'G','O','A','E','T',
					'X','T','N','Z','Y',
					'X','O','Q','R','S' };

char map2[5][5] = { 'N','N','N','N','S',
					'N','E','E','E','N',
					'N','E','Y','E','N',
					'N','E','E','E','N',
					'N','N','N','N','N' };

int x_p[8] = { -1,0,+1,-1,+1,-1,0,+1 };
int y_p[8] = { -1,-1,-1,0,0,+1,+1,+1 };

vector<int> find_x;
vector<int> find_y;

void string_find(string str, int x, int y)
{
	if (str.empty()) {
		cout << "찾았습니다" << endl;
		return;
	}
	if (str.back() == map2[x][y])
	{
		str.pop_back();
		map2[x][y] = tolower(map2[x][y]);
		for (int i = 0; i < 8; i++) {
			string_find(str, x + x_p[i], y + y_p[i]);
		}
	}
}

int main()
{
	string s;
	int size = 0;
	int i, j;
	cin >> s;
	// 문자열 먼저 뒤집기
	reverse(s.begin(), s.end());

	//첫째글자 먼저 찾고 탐색
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (s.back() == map2[i][j])
			{
				string_find(s, i, j);
			}
		}
	}

	return 0;
}
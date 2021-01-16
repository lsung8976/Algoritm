#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& n1, int& n2)
{
	int temp;
	temp = n2;
	n2 = n1;
	n1 = temp;
}

int solution(int s, int* arr)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (s - (arr[i] + arr[j]) == 100)
			{
				arr[i] = arr[j] = 0;
				return 0;
			}
		}
	}
}

int main()
{
	int height[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i];
	}

	solution(sum, height);

	sort(height, height + 9);

	for(int i=2;i<9;i++)
		cout << height[i] << endl;

	return 0;
}
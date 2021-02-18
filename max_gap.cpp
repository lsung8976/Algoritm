f#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

bool next_permutation(int* _arr, int _n)
{
	int i = _n - 1;
	int  j = _n - 1;
	for (; _n >= 0; i--)
	{
		if (i == 0)
			return false;
		if (_arr[i - 1] < _arr[i])
			break;
	}

	for (; _n >= i; j--)
	{
		if (_arr[i - 1] < _arr[j])
		{
			swap(_arr[i - 1], _arr[j]);
			break;
		}
	}

	sort(_arr + i, _arr + _n);
	return true;
}

int calc(int* _arr, int _n)
{
	int sum = 0;
	for (int i = 0; i < _n - 1; i++)
		sum += abs(_arr[i] - _arr[i + 1]);
	return sum;
}

int main()
{
	int n;
	int* arr;
	int max_sum = 0;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	
	do
	{
		max_sum = (max_sum > calc(arr, n)) ? max_sum : calc(arr, n);
	} while (next_permutation(arr, n));
	
	cout << max_sum;


	delete[] arr;

	return 0;
}
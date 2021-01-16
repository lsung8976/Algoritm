#include <iostream>
using namespace std;

void swap(int &a , int &b)
{
	int temp = b;
	b = a;
	a = temp;
}

bool next_permutation(int *a, int n)
{
	int i = 0;
	int j = 0;
	for (i = n - 1; i >= 0; i--)
	{
		if (i == 0)
			return false;
		if (a[i - 1] < a[i])
			break;
	}
	
	for (j = n - 1; j >= 0; j--)
	{
		if (a[i - 1] < a[j])
			break;
	}

	swap(a[i - 1], a[j]);
	
	for (int k = i; k < n - 1; k++)
	{
		for (int l = k + 1; l < n; l++)
		{
			if (a[k] > a[l])
				swap(a[k], a[l]);
		}
	}
	
	return true;
}


int main()
{
	int arr[7] = { 1,1,1,1,2,2,2 };
	int arr1[7] = { 7,6,5,4,3,2,1 };
	int size = 7;
	/*
	if (!next_permutation(arr, size))
		cout << "마지막 순열" << endl;
	else
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	*/
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	while (next_permutation(arr, size))
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

}
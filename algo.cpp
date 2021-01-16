#include <iostream>
using namespace std;
/*
int Comb(int a, int b)
{
	if (b > a)
	{
		cout << "잘못된 조합식입니다. " << endl;
		return 0;
	}
	int up_sum = 1;
	int down_sum = 1;
	for (int i = a; i > a - b; i--) // npr
	{
		up_sum *= i;
	}
	for (int i = 1; i <= b; i++) //r!
	{
		down_sum *= i;
	}
	return up_sum / down_sum; // nPr / r!
}*/

int Comb(int n, int r) // 인터넷펌
{
	if (n == r || r == 0) return 1;
	// nCr = (n-1)C(r-1) + (n-1)C(r)
	return Comb(n - 1, r - 1) + Comb(n - 1, r);
}

int even_num(int num)
{
	if (num == 2)
		return 2;
	int sum = 0;
	for (int i = 1; i <= num/2; i++)
	{
		sum += Comb(num - i, i);
	}
	return sum + 2; // 2는 전체 세로일때나 전체 가로블럭일때 각각 두가지 경우 더하기
}

int odd_num(int num)
{
	int sum = 0;
	for (int i = 1; i <= num / 2; i++)
	{
		sum += Comb(num - i, i);
	}
	return sum + 1; // 2는 전체 세로일때나 전체 가로블럭일때 각각 두가지 경우 더하기
}

int main(void)
{
	int n;
	int output;
	cin >> n;
	
	if (n % 2)
		output = odd_num(n);
	else
		output = even_num(n);

	cout << output << endl;
	return 0;
}
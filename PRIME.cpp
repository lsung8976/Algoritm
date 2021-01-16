#include <iostream>
#include <vector>
using namespace std;

int num = 0;

bool prime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int time;
	cin >> time;
	vector<int> v(time);
	for (int i = 0; i < time; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < time; i++)
	{
		if (prime(v[i]))
			cout << v[i] <<"는 소수가 맞습니다." << endl;
	}

	return 0;
}
#include <iostream>
using namespace std;

void decimal(int _a, int _b)
{
	int cnt = 0;
	while (_a != 0)
	{
		cout << _a / _b;
		if (++cnt == 1) cout << ".";
		_a = (_a % _b) * 10;
	}
}

int main()
{
	int a;
	int b;

	cin >> a;
	cin >> b;
	
	decimal(a, b);

	cout << endl;
}
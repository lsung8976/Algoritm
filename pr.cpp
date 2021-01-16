/*#include <iostream>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	//Á¡È­½Ä f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4);

	vector<int> v(20);
	int num;
	int count;
	

	v[0] = 1;	//0
	v[1] = 2;	//0
	v[2] = 4;	//0

	for (int i = 3; i < 20; i++)
	{
		v[i] = v[i - 1] + v[i - 2] + v[i - 3];
	}

	
	cin >> count;
	for(int i  = 0; i<count ; i++)
	{
		cin >> num;
		cout << v[num - 1] << endl;
	}

	return 0;
}*/



#include <iostream>
using namespace std;

int total = 0;
int go(int _cnt, int _sum, int _goal)
{
	if (_sum > _goal) return 0;
	if (_sum == _goal)
	{
		total++;
		return 0;
	}
	if (_sum < _goal)
	{
		for (int i = 1; i <= 3; i++)
		{
			go(_cnt + 1, _sum + i, _goal);
		}

	}
}

int main()
{
	int cnt = 0;
	int sum = 0;
	int goal;
	cin >> goal;

	go(cnt, sum, goal);
	
	cout << total << endl;

}
#include <iostream>
#include <cmath>
#define MIN 0
using namespace std;


double go(int* A, int& _day, int& _n_team) {
	int N = _day, ret = MIN, psum = 0;
	for (int i = 0; i < N; ++i) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
}

/*
double go(int* arr, int& _day, int& _n_team)
{
	//double avg = arr[_day;
	double ret = 100000;
	for (int i = 0; i < _day - _n_team; i++)
	{
		avg = min(ret, go(arr, _day, _n_team));
		ret = min(ret, avg);
	}
	return ret;
}
*/

int main()
{
	int Case;
	int day;
	int n_team;
	int* day_pay;

	int a = 1;
	int b = 2;

	double dap;
	
	cin >> Case;
	while (Case != 0)
	{
		cin >> day;
		cin >> n_team;
		day_pay = new int[day];
		
		for (int i = 0; i < day; i++)
			cin >> day_pay[i];

		cout << go(day_pay, day, n_team)<< endl;

		Case -= 1;
	}

	return 0;
}
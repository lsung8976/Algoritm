#include <iostream>
#include <vector>
using namespace std;
/*
* n : 전체 원소 수
* picked : 지금까지 고른 원소들의 번호
* toPick : 더 고를 원소의 수
* 일때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력한다.
* */
void printPicked(vector<int>& picked)
{
	for (vector<int>::iterator iter = picked.begin(); iter != picked.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void run(int n, vector<int>& basket, int pick_num)
{
	//기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력한다.
	if (pick_num == 0) { printPicked(basket); return; }
	//고를 수 있는 가장 작은 번호를 계산한다.
	int first = basket.empty() ? 0 : basket.back() + 1;
	// 이 단계에서 원소 하나를 고른다.
	for (int i = first; i < n; i++)
	{
		basket.push_back(i);
		run(n, basket, pick_num - 1);
		basket.pop_back();
	}
}

int main()
{
	vector<int> v;
	run(7, v, 4);

	return 0;
}